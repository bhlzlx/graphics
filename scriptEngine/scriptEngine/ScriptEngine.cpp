#include "ScriptEngine.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <buffer/buffer.h>

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
	
	/*
	template<>
	void ScriptEngine::CallScript<void>( const char * _szScriptFunc )
	{
		LuaRef trace = getGlobal (m_L, "trace");
		trace();
	}
	
	template <class T1>
	void ScriptEngine::CallScript<T1>( const char * _szScriptFunc , T1 _t1)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1);
		return;
	}
	
	template < void , class T1, class T2>
	void ScriptEngine::CallScript<void>( const char * _szScriptFunc , T1 _t1, T2 _t2)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2);
		return;
	}
	template < void , class T1, class T2, class T3>
	void ScriptEngine::CallScript<void>( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3);
	}
	template < void , class T1, class T2, class T3, class T4>
	void ScriptEngine::CallScript<void>( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3, _t4);
	}
	template < void , class T1, class T2, class T3, class T4, class T5>
	void ScriptEngine::CallScript<void>( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3, _t4, _t5);
	}
	template < void, class T1, class T2, class T3, class T4, class T5, class T6>
	void ScriptEngine::CallScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3, _t4, _t5, _t6);
	}
	template < void, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
	void ScriptEngine::CallScript<void>( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3, _t4, _t5, _t6, _t7);
	}
	template < void , class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
	void ScriptEngine::CallScript<void>( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T8 _t8)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8);
	}*/

}


