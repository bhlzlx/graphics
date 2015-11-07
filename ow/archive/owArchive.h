#ifndef __OW_ARCHIVE_H__
#define __OW_ARCHIVE_H__

#include <package/owPackage.h>

namespace ow
{
	struct owArchive
	{
		owArchive();
		~owArchive();
		void Init( const char * _szRootpath, const char * _szRootpackpath );
		owFile * Open( const char * _szFilepath);
		
		owPackage*			m_pRootPackage;
		char				m_pathPrefix[64];
	};
	
	owArchive * GetArchive();
}

#endif // __OW_ARCHIVE_H__
