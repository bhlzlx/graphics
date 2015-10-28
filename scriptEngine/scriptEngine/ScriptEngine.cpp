#include "ScriptEngine.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <buffer.h>

namespace ow
{
	ScriptEngine scriptEngine_g;
	
	ScriptEngine::ScriptEngine()
	{
	}

	ScriptEngine::~ScriptEngine()
	{
	}
	
	void ScriptEngine::Init()
	{
		m_L = luaL_newstate();
		luaopen_base(m_L);
		luaL_openlibs(m_L);
		
		#include "script_reg_def.h"
		
	}
	
	void ScriptEngine::LoadScript( const char * _szFilepath )
	{
		luaL_dofile(m_L, _szFilepath);
	}
	
	void ScriptEngine::CallVoidScript( const char * _szScriptFunc )
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func();
	}
	
}


