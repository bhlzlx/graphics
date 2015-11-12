#include "owArchive.h"
#include <cmn/owstring.h>
#include <assert.h>

namespace ow
{
	owArchive* archive__ = NULL;
	
	owArchive * GetArchive()
	{
		if(archive__ == NULL)
		{
			archive__ = new owArchive;
		}
		return archive__;
	}

	owArchive::owArchive()
	{
		this->m_pRootPackage = NULL;
	}

	owArchive::~owArchive()
	{
		if( m_pRootPackage )
		{
			m_pRootPackage->Release();
		}
	}
	
	void owArchive::Init( const char * _szRootpath, const char * _szRootpackpath )
	{
		memset(&m_pathPrefix[0],0, 64);
		this->m_pRootPackage = new owPackage;
		owBOOL ret = m_pRootPackage->Init( _szRootpackpath);
		if(ret == owFALSE)
		{
			delete m_pRootPackage;
			m_pRootPackage = NULL;
		}
		
		memcpy(m_pathPrefix, _szRootpath, strlen(_szRootpath));
	}
	
	owFile * owArchive::Open( const char * _szFilepath)
	{
		// 优先查找本地文件
		owPath * path = CreatePath( _szFilepath);
		std::string fullpath = std::string( m_pathPrefix);
		fullpath = fullpath + path->m_strFullpath;
		owFile * file = CreateStdFile(fullpath.c_str(),"rb");
		delete path;
		if(file)
		{			
			return file;
		}
		if( m_pRootPackage)
		{
			file = m_pRootPackage->Open( fullpath.c_str() );
			if(file)
			{
				return file;
			}
		}
		return nullptr;
	}

}

