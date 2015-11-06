#ifndef __RESOURCE_POOL_H__
#define __RESOURCE_POOL_H__

#include <memory/memory.h>
#include <package/owPackage.h>

#define RESOURCE_STRING_LENGTH_MAX 2048

#define RESOURCE_CHECK_STRING_LENGTH( n )\
	if(n > RESOURCE_STRING_LENGTH_MAX)\
		assert(false);\
		
namespace resource
{
	void Init();
	void Release();
	
	ow::owPackage * GetPackage();	
	
	extern const owINT32 STRING_LENGTH_MAX;
	owCHAR * AllocString();
	void ReleaseString( owVOID * _string);
}
		


#endif // __RESOURCE_POOL_H__
