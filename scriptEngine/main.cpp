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

struct Object
{
	int 	m_type;
	void trace()
	{
		printf("Object::trace()::m_type = %d\n",m_type);
	}
};

using namespace luabridge;

int main(int argc, char **argv)
{
	lua_State * L = luaL_newstate();
	luaopen_base(L);
	luaL_openlibs(L);
	
	getGlobalNamespace(L)
		.beginClass<Object>("Object")
			.addConstructor<void(*)(void)>()
			.addData("m_type", &Object::m_type)
			.addFunction("trace", &Object::trace)
		.endClass();
	
	luaL_dofile(L,"script.lua");
	
	LuaRef trace = getGlobal (L, "trace");
	trace();
	
	system("pause");
	return 0;
}
