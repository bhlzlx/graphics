#include "owPackage.h"
#include <stack>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmn/owstring.h>
#include <crypto/md5.h>

namespace ow
{
	owPath *  CreatePath( const char * _szPath)
	{
		char * buff = new char[strlen(_szPath) + 1];
		strcpy(buff, _szPath);
		owPath * pathObj = new owPath;
		std::list< std::string>& pathList = pathObj->m_pathList;
		std::string& fullpath = pathObj->m_strFullpath;
		char * pch = strtok (buff,"/\\");
		while (pch != NULL)
		{
			if( strcmp(pch,".") == 0)
			{
				// skip
			}
			else if( strcmp(pch, "..") == 0)
			{
				pathList.pop_back();
			}
			else
			{
				tolowercase(pch,strlen(pch));
				pathList.push_back(pch);
			}
			pch = strtok (NULL, "/\\");
		}

		for( std::string & section : pathList)
		{
			fullpath.push_back( '/' );
			fullpath.append( section);
		}

		delete []buff;
		return pathObj;
	}

	owBOOL owPackage::Init(const owCHAR* _szPackPath)
	{
		m_pPackFile = ow::CreateStdFile( _szPackPath, "rb");
		m_pPath = CreatePath( _szPackPath);
		if(m_pPackFile == NULL)
		{
			return owFALSE;
		}

		ow::owPackHeader packHeader;
		m_pPackFile->Read( &packHeader, sizeof(packHeader));
		owINT32 nFiles = packHeader.m_nFileTags;

		m_pFileTags = new ow::owFileTag[ nFiles];
		m_pNodes = new ow::owNodeR[ nFiles];
		m_pPackFile->Read( m_pFileTags, sizeof(ow::owFileTag) * nFiles);

		for(int i = 0; i<nFiles; ++i)
		{
			m_pNodes[i].m_iNodeID = i;
			if(m_pFileTags[i].m_iFileType == FILETYPE_DIR)
			{
				owINT32 numChild = m_pFileTags[i].m_nBytes;
				m_pNodes[i].m_pChildrenNodes = new owINT32[numChild];
				m_pPackFile->Seek( SEEK_SET, m_pFileTags[i].m_nDataOffset);
				m_pPackFile->Read(m_pNodes[i].m_pChildrenNodes, sizeof(owINT32) * numChild);
			}
			else
			{
				m_pNodes[i].m_pChildrenNodes = NULL;
			}
		}
		return owTRUE;
	}

	owFile* owPackage::Open(const owCHAR* _szPath)
	{
		owPath * path = CreatePath(_szPath);
		ow::owNodeR * currNode = &this->m_pNodes[0];
		std::list< std::string>::iterator iter = path->m_pathList.begin();
		std::list< std::string>::iterator iterLast = path->m_pathList.end();
		iterLast--;
		// 找目录
		while(iter != iterLast)
		{
			ow::owFileTag * currFile = &m_pFileTags[currNode->m_iNodeID];
			assert(currFile->m_iFileType == FILETYPE_DIR);

			ow::owNodeR * nextDir = NULL;
			for(int i = 0; i < currFile->m_nBytes; ++i)
			{
				owFileTag * file = &this->m_pFileTags[ currNode->m_pChildrenNodes[i] ];
				if(file->m_iFileType == FILETYPE_DIR && strcasecmp(file->m_szFileName,iter->c_str() ) == 0)
				{
					nextDir = &this->m_pNodes[ currNode->m_pChildrenNodes[i] ];
					break;
				}
			}
			if(nextDir == NULL)
			{
				delete path;
				return NULL;
			}
			currNode = &m_pNodes[ nextDir->m_iNodeID ];
			++iter;
		}

		// 找文件
		ow::owFileTag * currFile = &m_pFileTags[currNode->m_iNodeID];
		ow::owFileTag * targetFile = NULL;
		for( int i = 0; i<currFile->m_nBytes; ++i)
		{
			owFileTag * file = &this->m_pFileTags[ currNode->m_pChildrenNodes[i] ];
			if(file->m_iFileType == FILETYPE_FILE && strcasecmp(file->m_szFileName,iter->c_str() ) == 0)
			{
				targetFile = &this->m_pFileTags[ currNode->m_pChildrenNodes[i] ];
				break;
			}
		}
		if(targetFile == NULL)
		{
			delete path;
			return NULL;
		}
		// 解压文件，创建buffer,校验md5
		owZip ziper;
		MD5 md5er;
		ow::owMemFile * memFile = (ow::owMemFile*)CreateMemFile( targetFile->m_nBytes);
		m_pPackFile->Seek( SEEK_SET, targetFile->m_nDataOffset);
		m_pPackFile->Read( memFile->m_pMemBuffer->GetBuffer(), targetFile->m_nBytes);
		ow::owFile * file = ziper.Uncompress(memFile);
		static char md5info[32];
		md5er.Compute(file);
		md5er.GetValue(&md5info[0]);
		printf("file : %s\n",targetFile->m_szFileName);
		if(memcmp( md5info,targetFile->m_md5,32) == 0)
		{
			printf("md5 check : pass!\n");
		}
		else
		{
			printf("md5 check : failed!\n");
		}

		file->Seek( SEEK_SET, 0);
		delete path;
		return file;
	}

	owPackage::owPackage()
	{

	}

	owPackage::~owPackage()
	{

	}

	owVOID owPackage::Release()
	{
		delete []this->m_pFileTags;
		delete []this->m_pNodes;
		delete this->m_pPath;
		this->m_pPackFile->Release();
		delete this;
	}
}




