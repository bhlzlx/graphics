#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <scriptEngine/ScriptEngine.h>

#include <string>
#include <buffer/buffer.h>

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
		
		ow::owBuffer * pBuffer = engine.CallScript<ow::owBuffer*>("script_MemBufferRet");
		printf("owBuffer test : %s", pBuffer->GetBuffer());
		engine.CallVoidScript("script_MemBufferRelease");
		
	}
	catch( luabridge::LuaException& e)
	{
		printf( e.what() );
	}

	system("pause");
	return 0;
}
