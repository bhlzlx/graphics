#ifndef __OW_ARCHIVE_H__
#define __OW_ARCHIVE_H__

#include <package/owPackage.h>
#include <foundation/owVector.h>

namespace ow
{
	class owArchive
	{
	public:
		owArchive();
		~owArchive();
		void Init( const char * _szRootpath, const char * _szRootpackpath );
		owFile * Open( const char * _szFilepath);
	private:
		owPackage*			m_pRootPackage;
		char				m_pathPrefix[64];
	};
}

#endif // __OW_ARCHIVE_H__
