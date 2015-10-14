#ifndef __OW_PACKAGE_H__
#define __OW_PACKAGE_H__

#include <owfile/owfile.h>
#include <owZip/owZip.h>
#include <package/package_common.h>
#include <list>

namespace ow
{
	struct owPath
	{
		std::list< std::string>		m_pathList;
		std::string					m_strFullpath;
	};
	
	owPath * CreatePath( const owCHAR* _szPath);
	
	struct owPackage
	{
		owPackage();
		~owPackage();
		
		owBOOL Init(const owCHAR * _szPackPath);
		
		owFile * Open( const owCHAR * _szPath );
		owVOID Release();
		
		owFile*			m_pPackFile;
		
		owNodeR * 		m_pNodes;
		owFileTag * 	m_pFileTags;
	};

}

#endif // __OW_PACKAGE_H__
