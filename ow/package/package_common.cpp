#include <package/package_common.h>
#include <package/owPackage.h>
#include <owfile/owfile.h>
#include <owZip/owZip.h>
#include <algorithm/md5.h>

namespace ow
{
	
	int32_t owSearchDir( const char *_szRoot, owNodeW *_pRootNode )
	{
		owPath * pPath = CreatePath(_szRoot);
		
		int32_t totalCount= 0;

		std::vector<std::string> nodeNames;
		DWORD attr= GetFileAttributesA( pPath->m_strFullpath.c_str() + 1 );
		_pRootNode->m_strNodeName= "/";
		_pRootNode->m_iFileType= FILETYPE_DIR;
		_pRootNode->m_pParent= NULL;
		_pRootNode->m_strFullpath= pPath->m_strFullpath.c_str() + 1;
		
		delete pPath;

		if( attr == INVALID_FILE_ATTRIBUTES || !( attr & FILE_ATTRIBUTE_DIRECTORY ) )
		{
			MessageBoxA( NULL, "Invalid Dir.", "Error", MB_OK );
			return 0;
		}

		++totalCount;
		std::queue<ow::owNodeW *> nodeQueue;
		nodeQueue.push( _pRootNode );
		WIN32_FIND_DATAA findData;

		while( !nodeQueue.empty() )
		{
			ow::owNodeW *pCurrNode= nodeQueue.front();
			std::string &currfolder= pCurrNode->m_strFullpath;
			nodeQueue.pop();
			// 处理源文件
			HANDLE firstFile;
			std::string fileName= currfolder + "/*.*";
			
			firstFile= FindFirstFileA( fileName.c_str(), &findData );

			if( INVALID_HANDLE_VALUE != firstFile )
			{
				if( findData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE )
				{
					ow::owNodeW *pNode= new ow::owNodeW;
					pNode->m_iFileType= FILETYPE_FILE;
					pNode->m_pParent= pCurrNode;
					pNode->m_strNodeName= findData.cFileName;
					pCurrNode->m_vecChildren.push_back( pNode );
					++totalCount;
				}

				while( FindNextFileA( firstFile, &findData ) )
				{
					// 文件
					if( findData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE )
					{
						ow::owNodeW *pNode= new ow::owNodeW;
						pNode->m_iFileType= FILETYPE_FILE;
						pNode->m_pParent= pCurrNode;
						pNode->m_strNodeName= findData.cFileName;
						pNode->m_strFullpath= pCurrNode->m_strFullpath + "/" + std::string( findData.cFileName );
						pCurrNode->m_vecChildren.push_back( pNode );
						++totalCount;
					}
					// 子目录
					else if( findData.cFileName[0] != '.' && findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
					{
						ow::owNodeW *pNode= new ow::owNodeW;
						pNode->m_iFileType= FILETYPE_DIR;
						pNode->m_pParent= pCurrNode;
						pNode->m_strNodeName= findData.cFileName;
						pNode->m_strFullpath= pCurrNode->m_strFullpath + "/" + findData.cFileName + "/";
						pCurrNode->m_vecChildren.push_back( pNode );
						nodeQueue.push( pNode );
						++totalCount;
					}
				}
			}
		}

		return totalCount;
	}

	owBOOL owCreatePackage( ow::owNodeW *_pRootNode, owINT32 _nNodeNum, const owCHAR *_szFilepath )
	{
		std::vector<ow::owNodeW *> linearNodes;
		std::queue<ow::owNodeW *> folderQueue;

		folderQueue.push( _pRootNode );

		while( !folderQueue.empty() )
		{
			owNodeW *pwd= folderQueue.front();
			folderQueue.pop();
			linearNodes.push_back( pwd );

			for( owNodeW *pNode : pwd->m_vecChildren )
			{
				if( pNode->m_iFileType == FILETYPE_DIR )
				{
					folderQueue.push( pNode );
				}
				else
				{
					linearNodes.push_back( pNode );
				}
			}
		}

		// assign node's index_id
		for( size_t i= 0; i < linearNodes.size(); ++i )
		{
			linearNodes[i]->m_iIndexId= i;
		}

		ow::owFile *packFile= ow::CreateStdFile( _szFilepath, "wb" );
		assert( packFile );
		int32_t packTagOffset= sizeof( owPackHeader );                                        // 写入tags数据的区域
		int32_t packContentOffset= linearNodes.size() * sizeof( owFileTag ) + packTagOffset;  // 写入文件正文的起始区域

		owPackHeader header;
		header.m_iVersion= 'O' << 24 | 'W' << 16 | 'P' << 8 | 'K';
		header.m_nContentOffset= packContentOffset;
		header.m_nEmptyFileTags= 0;
		header.m_nFileTags= linearNodes.size();
		packFile->Write( (int8_t *)&header, sizeof( header ) );

		// 写文件头
		owFileTag fileTag;
		ow::owZip zipObject;
		MD5 md5er;
		ow::owFile *stdFile= NULL;
		owBuffer *packBuffer= NULL;

		for( size_t i= 0; i < linearNodes.size(); ++i )
		{
			stdFile= NULL;
			packBuffer= NULL;
			ow::owNodeW *pNodeRef= linearNodes[i];
			// 文件类型
			fileTag.m_iFileType= pNodeRef->m_iFileType;

			// 文件名
			if( pNodeRef->m_strNodeName.length() > FILENAME_LENGTH_MAX )
			{
				assert( false );
			}

			strcpy( &fileTag.m_szFileName[0], pNodeRef->m_strNodeName.c_str() );
			// 读取偏移位置
			fileTag.m_nDataOffset= packContentOffset;

			// 如果是普通文件，则读取内容，压缩成二进制数据
			if( fileTag.m_iFileType == FILETYPE_FILE )
			{
				stdFile= ow::CreateStdFile( pNodeRef->m_strFullpath.c_str(), "rb" );
				assert( stdFile );
				packBuffer= zipObject.RefCompress( stdFile, 9 );
				// md5
				md5er.Compute( stdFile );
				md5er.GetValue( (char *)&fileTag.m_md5[0] );
				// 原始大小
				fileTag.m_nOrigBytes= stdFile->Size();
				// 包内大小
				fileTag.m_nBytes= packBuffer->Size();
				stdFile->Release();
			}
			else  // 如果是目录，则直接创建一个buffer,存filetag编号
			{
				uint32_t fileNum= pNodeRef->m_vecChildren.size();

				if( fileNum != 0 )
				{
					packBuffer= CreateMemBuffer( fileNum * sizeof( int32_t ) );
					int32_t *pInts= (int32_t *)packBuffer->GetBuffer();

					for( size_t fileN= 0; fileN < fileNum; ++fileN )
					{
						pInts[fileN]= pNodeRef->m_vecChildren[fileN]->m_iIndexId;
					}
				}

				// 文件夹对应文件数量，不对应内容大小
				fileTag.m_nBytes= fileNum;
				// 原始大小为0
				fileTag.m_nOrigBytes= 0;
				// md5
				memset( fileTag.m_md5, 0, 32 );
			}

			// 写入tag
			packFile->Seek( SEEK_SET, packTagOffset );
			packTagOffset+= packFile->Write( (int8_t *)&fileTag, sizeof( fileTag ) );

			// 写入数据
			if( packBuffer )
			{
				packFile->Seek( SEEK_SET, packContentOffset );
				packContentOffset+= packFile->Write( packBuffer->GetBuffer(), packBuffer->Size() );
				packBuffer->Release();
			}
		}

		packFile->Release();
		return true;
	}
}

void ow::owNodeW::Sort()
{
	std::sort( m_vecChildren.begin(), m_vecChildren.end(), []( ow::owNodeW *i, ow::owNodeW *j )
	{
		return i->m_iFileType > j->m_iFileType;
	} );
}

void ow::owNodeW::Print( int _nAlignSpace )
{
	for( int i= 0; i < _nAlignSpace; ++i )
	{
		printf( "    " );
	}

	printf( "%s \n", m_strFullpath.c_str() );

	for( ow::owNodeW *pNode : m_vecChildren )
	{
		pNode->Print( _nAlignSpace + 1 );
	}
}

void ow::owNodeW::Release()
{
	for( ow::owNodeW *pNode : m_vecChildren )
	{
		pNode->Release();
	}

	delete this;
}
