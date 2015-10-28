#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <scriptEngine/ScriptEngine.h>

#include <string>
#include <buffer.h>

using namespace luabridge;

int main(int argc, char **argv)
{
	try
	{
		ow::ScriptEngine &engine = ow::scriptEngine_g;
		engine.Init();
		engine.LoadScript("script.lua");
		engine.CallVoidScript("script_VoidFunction");
		int iValue = engine.CallScript<int>("script_GetIntValue");
		float fValue = engine.CallScript<float>("script_GetFloatValue");
		std::string strValue = engine.CallScript<std::string>("script_GetStringValue");
		
		engine.CallVoidScript("script_VoidParam1",iValue);
		iValue = engine.CallScript<int>("script_Param1",iValue);
		printf("%d %f %s",iValue,fValue,strValue.c_str());
		
		owINT32 (ow::MemBuffer::* fp)(const owVOID* ,owINT32) = &ow::MemBuffer::Write;
		ow::MemBuffer * pBuff = ow::CreateMemBuffer( 32);
		(pBuff->*fp)("hello,world!",13);
		int size = engine.CallScript<int>("script_MemBufferSize", pBuff);
		printf("buffer size : %d", size);
		engine.CallVoidScript("script_MemBufferResize",pBuff,64);
		size = engine.CallScript<int>("script_MemBufferSize", pBuff);
		printf("buffer size : %d", size);
		engine.CallVoidScript("script_MemBufferWrite",pBuff,(void*)&size,sizeof(int));
	}
	catch( luabridge::LuaException& e)
	{
		printf( e.what() );
	}

	system("pause");
	return 0;
}
