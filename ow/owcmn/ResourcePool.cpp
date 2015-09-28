#include "ResourcePool.h"

void InitResourcePool()
{
	STRING_POOL_PTR = new ow::SMemPool(_GLOBAL_STRING_BUFFER_MAX_,_GLOBAL_STRING_BUFFER_MAX_);
}

void ReleaseResourcePool()
{
	if(STRING_POOL_PTR)
	{
		delete STRING_POOL_PTR;
		STRING_POOL_PTR = NULL;
	}
}

ow::SMemPool*		STRING_POOL_PTR = NULL;