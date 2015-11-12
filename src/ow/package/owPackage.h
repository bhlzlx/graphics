#ifndef __OW_PACKAGE_H__
#define __OW_PACKAGE_H__

#include <file/owfile.h>
#include <Zip/owZip.h>
#include <package/package_common.h>
#include <list>

namespace ow
{
	struct owPath
	{
		std::list< std::string>		m_pathList;
		std::string					m_strFullpath;

		bool operator== (const owPath& _path)
		{
			if(m_pathList.size() != _path.m_pathList.size())
			{
				return false;
			}
			std::list< std::string>::iterator itera = m_pathList.begin();
			std::list< std::string>::iterator iterb = m_pathList.begin();

			for(; itera != m_pathList.end(); ++itera,++iterb)
			{
				if( *itera != *iterb)
				{
					return false;
				}
			}
			return true;
		}
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
		owPath*			m_pPath;

		owNodeR * 		m_pNodes;
		owFileTag * 	m_pFileTags;
	};

}

#endif // __OW_PACKAGE_H__
