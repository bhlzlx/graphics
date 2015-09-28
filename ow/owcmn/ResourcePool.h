#ifndef __RESOURCE_POOL_H__
#define __RESOURCE_POOL_H__

#include <memory/memory.h>

#define _GLOBAL_STRING_BUFFER_MAX_ 2048

#define _CHECK_STRING_BUFFER_OVERFLOW_( n )\
	if(n > _GLOBAL_STRING_BUFFER_MAX_)\
		assert(false);\
		
void InitResourcePool();
void ReleaseResourcePool();

extern ow::SMemPool*		STRING_POOL_PTR;

#endif // __RESOURCE_POOL_H__
