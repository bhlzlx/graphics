#include <package/package_common.h>

namespace ow
{
	int32_t owSearchDir(const char * _szRoot, owNode * _pRootNode)
	{
		int32_t totalCount = 0;
		
		std::vector< std::string> nodeNames;
		DWORD attr = GetFileAttributesA(_szRoot);
		_pRootNode->m_strNodeName = "/";
		_pRootNode->m_iFileType = FILETYPE_DIR;
		_pRootNode->m_pParent = NULL;
		_pRootNode->m_strFullpath = _szRoot;
		
		if (attr == INVALID_FILE_ATTRIBUTES ||!(attr & FILE_ATTRIBUTE_DIRECTORY))
		{
			MessageBoxA(NULL,"Invalid Dir.","Error",MB_OK);
			return;
		}
		++totalCount;
		std::queue< ow::owNode *> nodeQueue;
		nodeQueue.push( _pRootNode);
		WIN32_FIND_DATAA findData;
		while(!nodeQueue.empty())
		{
			ow::owNode * pCurrNode = nodeQueue.front();
			std::string& currfolder = pCurrNode->m_strFullpath;
			nodeQueue.pop();
			// 处理源文件
			HANDLE firstFile;
			std::string fileName = currfolder + "*.*";
			firstFile = FindFirstFileA(fileName.c_str(),&findData);
			
			
			if (INVALID_HANDLE_VALUE != firstFile)
			{
				if (findData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
				{
					ow::owNode * pNode = new ow::owNode;
					pNode->m_iFileType = FILETYPE_FILE;
					pNode->m_pParent = pCurrNode;
					pNode->m_strNodeName = findData.cFileName;
					pCurrNode->m_vecChildren.push_back(pNode);
					++totalCount;
				}
				while (FindNextFileA(firstFile,&findData))
				{
					// 文件
					if (findData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
					{
						ow::owNode * pNode = new ow::owNode;
						pNode->m_iFileType = FILETYPE_FILE;
						pNode->m_pParent = pCurrNode;
						pNode->m_strNodeName = findData.cFileName;
						pNode->m_strFullpath = pCurrNode->m_strFullpath + "/" + std::string(findData.cFileName);
						pCurrNode->m_vecChildren.push_back(pNode);
						++totalCount;
					}
					// 子目录
					else if( findData.cFileName[0] != '.' && findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
					{
						ow::owNode * pNode = new ow::owNode;
						pNode->m_iFileType = FILETYPE_DIR;
						pNode->m_pParent = pCurrNode;
						pNode->m_strNodeName = findData.cFileName;
						pNode->m_strFullpath = pCurrNode->m_strFullpath + "/" + findData.cFileName + "/";
						pCurrNode->m_vecChildren.push_back(pNode);
						nodeQueue.push( pNode );
						++totalCount;
					}
				}
			}
		}
		return totalCount;
	}
	
	
	bool owCreatePackage( ow::owNode* _pRootNode, const char * _szFilepath)
	{
		ow::owFile * packFile = ow::CreateStdFile(_szFilepath, "wb");
		owPackHeader header;
		header.m_iVersion = 'O'<<24|'W'<<16|'P'<<8|'K';
		header.m_nContentOffset = 0;
		header.m_nEmptyFileTags = 0;
		header.m_nFileTags = 0;
	}
}