/*#include <stdio.h>
#include <assert.h>

#include "md5Frame.h"

using namespace Graphics::MD5;

int main(int argc, char **argv)
{
	IBuffer * pMeshBuff = BufferFromFile("./Bob.md5mesh");
	IBuffer * pAnimBuff = BufferFromFile("./Bob.md5anim");
	// 断言
	assert(pMeshBuff && pAnimBuff);
	// 解析MD5文件
	MD5File file;
	MD5FilePtr pFile = &file;
	Graphics::MD5::ParseMD5(pMeshBuff,pAnimBuff,pFile);
    
    MD5DefaultFrame frame;
	GetMD5DefaultFrame(&frame,pFile);

	Graphics::MD5::ClearMD5(&file);    
	return 0;
}
*/