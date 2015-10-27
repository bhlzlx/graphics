#ifndef __OW_SCRIPT_ENGINE_H__
#define __OW_SCRIPT_ENGINE_H__

#include <stdio.h>
#include <stdlib.h>
extern "C"
{
	#include <lua/lua.h>
	#include <lua/luaconf.h>
	#include <lua/lualib.h>
	#include <lua/lauxlib.h>
}

#include <LuaBridge/LuaBridge.h>
using namespace luabridge;

#define REG_SCRIPT_BEGIN								getGlobalNamespace( scriptEngine_g.m_L )
#define REG_SCRIPT_END									;

#define REG_NAMESPACE_BEGIN( __namespace )				.beginNamespace( #__namespace )
#define REG_NAMESPACE_END								.endNamespace()

#define REG_FREE_VAR( __var )							.addVariable( #__var, &__var )
#define REG_FREE_FUNC( __func )							.addFunction( #__func, &__func )

#define REG_CLASS_BEGIN( __class )						.beginClass<__class>( #__class )
#define REG_CLASS_DERIVE( __classA, __classB)			.deriveClass <__classB, __classA>(#__classB)
#define REG_CLASS_DERIVE_EXT( __classA, __classB, __name)\
														.deriveClass <__classB, __classA>(__name)
#define REG_CLASS_BEGIN_EXT( __class, __name )			.beginClass<__class>( __name )
#define REG_CLASS_END									.endClass()
#define REG_CLASS_DATA( __class, __data )				.addData( #__data, &__class::__data )
#define REG_CLASS_FUNC( __class, __func )				.addFunction( #__func, &__class::__func )
#define REG_CLASS_FUNC_EXT( __class, __func, __ret, __param )\
														.addFunction<__ret (__class::*)( __param )>( #__func, &__class::__func )
#define REG_CLASS_STATIC_DATA( __class, __data ) 		.addStaticData( #__class, #__data )
#define REG_CLASS_STATIC_FUNC( __class, __func ) 		.addStaticFunction( #__class, &__class::__func )
#define REG_CLASS_DEFAULT_CONSTRUCTOR					.addConstructor<void(*)(void)>()


namespace ow
{
	class ScriptEngine
	{
	public:
		enum LuaDataType
		{
			type_nil = LUA_TNIL,
			type_number = LUA_TNUMBER,
			type_string = LUA_TSTRING,
			type_table = LUA_TTABLE,
			type_function = LUA_TFUNCTION,
			type_userdata = LUA_TUSERDATA,
			type_thread = LUA_TTHREAD,
			type_lightuserdata = LUA_TLIGHTUSERDATA
		};
		lua_State *	m_L;
	public:
		ScriptEngine();
		~ScriptEngine();
		
		void Init();
		// 加载Lua脚本（文件系统）
		void LoadScript( const char * _szFilepath );
		// 加载Lua脚本（从脚本载入）
		// void LoadScript( ow::owBuffer * _pScriptBuffer);
		// 调用Lua脚本 （返回与无返回版本皆有）
		
		template < class T >
		T CallScript( const char * _szScriptFunc );
		template < class T, class T1>
		T CallScript( const char * _szScriptFunc, T1 _t1);
		template < class T, class T1, class T2>
		T CallScript( const char * _szScriptFunc, T1 _t1, T2 _t2);
		template < class T, class T1, class T2, class T3>
		T CallScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3);
		template < class T, class T1, class T2, class T3, class T4>
		T CallScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3, T4 _t4);
		template < class T, class T1, class T2, class T3, class T4, class T5>
		T CallScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5);
		template < class T, class T1, class T2, class T3, class T4, class T5, class T6>
		T CallScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6);
		template < class T, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
		T CallScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7);
		template < class T, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
		T CallScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7, T8 _t8);

		void CallVoidScript( const char * _szScriptFunc );
		template <class T1>
		void CallVoidScript( const char * _szScriptFunc, T1 _t1);
		template <class T1, class T2>
		void CallVoidScript( const char * _szScriptFunc, T1 _t1, T2 _t2);
		template <class T1, class T2, class T3>
		void CallVoidScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3);
		template <class T1, class T2, class T3, class T4>
		void CallVoidScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3, T4 _t4);
		template <class T1, class T2, class T3, class T4, class T5>
		void CallVoidScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5);
		template <class T1, class T2, class T3, class T4, class T5, class T6>
		void CallVoidScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6);
		template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
		void CallVoidScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7);
		template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
		void CallVoidScript( const char * _szScriptFunc, T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7, T8 _t8);
	private:
	};
	
	template < class T >
	T ScriptEngine::CallScript( const char * _szScriptFunc )
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		LuaRef ret = func();
		return ret.cast<T>();
	}
	
	template < class T , class T1>
	T ScriptEngine::CallScript( const char * _szScriptFunc , T1 _t1)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		LuaRef ret = func(_t1);
		return ret.cast<T>();
	}
	template < class T , class T1, class T2>
	T ScriptEngine::CallScript( const char * _szScriptFunc , T1 _t1, T2 _t2)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		LuaRef ret = func(_t1, _t2);
		return ret.cast<T>();
	}
	template < class T , class T1, class T2, class T3>
	T ScriptEngine::CallScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		LuaRef ret = func(_t1, _t2, _t3);
		return ret.cast<T>();
	}
	template < class T , class T1, class T2, class T3, class T4>
	T ScriptEngine::CallScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		LuaRef ret = func(_t1, _t2, _t3, _t4);
		return ret.cast<T>();
	}
	template < class T , class T1, class T2, class T3, class T4, class T5>
	T ScriptEngine::CallScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		LuaRef ret = func(_t1, _t2, _t3, _t4, _t5);
		return ret.cast<T>();
	}
	template < class T , class T1, class T2, class T3, class T4, class T5, class T6>
	T ScriptEngine::CallScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		LuaRef ret = func(_t1, _t2, _t3, _t4, _t5, _t6);
		return ret.cast<T>();
	}
	
	template < class T , class T1, class T2, class T3, class T4, class T5, class T6, class T7>
	T ScriptEngine::CallScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		LuaRef ret = func(_t1, _t2, _t3, _t4, _t5, _t6, _t7);
		return ret.cast<T>();
	}
	template < class T , class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
	T ScriptEngine::CallScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7, T8 _t8)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		LuaRef ret = func(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8);
		return ret.cast<T>();
	}
	
	template < class T1>
	void ScriptEngine::CallVoidScript( const char * _szScriptFunc , T1 _t1)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1);
	}
	template < class T1, class T2>
	void ScriptEngine::CallVoidScript( const char * _szScriptFunc , T1 _t1, T2 _t2)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2);
	}
	template <  class T1, class T2, class T3>
	void ScriptEngine::CallVoidScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3);
	}
	template < class T1, class T2, class T3, class T4>
	void ScriptEngine::CallVoidScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3, _t4);
	}
	template < class T1, class T2, class T3, class T4, class T5>
	void ScriptEngine::CallVoidScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3, _t4, _t5);
	}
	template < class T1, class T2, class T3, class T4, class T5, class T6>
	void ScriptEngine::CallVoidScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3, _t4, _t5, _t6);
	}
	
	template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
	void ScriptEngine::CallVoidScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3, _t4, _t5, _t6, _t7);
	}
	template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
	void ScriptEngine::CallVoidScript( const char * _szScriptFunc , T1 _t1, T2 _t2, T3 _t3, T4 _t4, T5 _t5, T6 _t6, T7 _t7, T8 _t8)
	{
		LuaRef func = getGlobal (m_L, _szScriptFunc);
		func(_t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8);
	}

	extern ScriptEngine scriptEngine_g;
}

#endif // __OW_SCRIPT_ENGINE_H__
