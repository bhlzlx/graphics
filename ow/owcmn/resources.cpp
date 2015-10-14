#include "resources.h"
#include <assert.h>
#include <owfile/owfile.h>

#define PACKAGE_PATH 			"package.pkg"
#define PREFERENCE_PATH			"config.txt"

namespace resource
{
	ow::owPackage*	 __package = NULL;
	ow::SMemPool*	 __stringPool = NULL;
	
	const owINT32 STRING_LENGTH_MAX = 1024;
	
	void Init()
	{
		// 初始化文件包
		__package = new ow::owPackage;
		owBOOL ret = __package->Init( PACKAGE_PATH );
		assert(ret == owTRUE);
		// 初始化字符串池
		__stringPool = new ow::SMemPool(8,RESOURCE_STRING_LENGTH_MAX);
		// 初始化配置文件
		ow::owMemFile * pConfigFile = (ow::owMemFile *)__package->Open( PREFERENCE_PATH );
		assert(pConfigFile);
		ow::GetPreference().Init( pConfigFile->m_pMemBuffer);
		pConfigFile->Release();
	}

	void Release()
	{
		if(__stringPool)
		{
			delete __stringPool;
			__stringPool = NULL;
		}
		
		if(__package)
		{
			__package->Release();
			__package = NULL;
		}
	}
	
	ow::owPackage * GetPackage()
	{
		return __package;
	}
	
	owCHAR * AllocString()
	{
		return (owCHAR *)__stringPool->Alloc(1);
	}
	
	void ReleaseString( owVOID * _string)
	{
		__stringPool->Recycle( _string);
	}
}