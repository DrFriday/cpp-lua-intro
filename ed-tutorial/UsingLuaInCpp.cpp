#pragma comment(lib,"lua5.1.lib")

#include <conio.h>
#include <iostream>
#include <sstream>

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
/* #1  Code used with test.lua
int main()
{
	// Create and start our environment
	lua_State *EnvOne = lua_open();

	// Load libs
	luaL_openlibs(EnvOne);

	// Run our "test.lua" file
	luaL_dofile(EnvOne, "test.lua");

	// Close our environment
	lua_close(EnvOne);

	return 0;

}*/

/* #2 Code used with script.lua
int main()
{
	// New Lua state
	std::cout << "[C++] Starting Lua state" << std::endl;
	lua_State *lua_state = luaL_newstate();

	// Load Lua Libraries
	luaL_openlibs(lua_state);

	// Start the arg table in Lua, uses the Lua stack, or a way
	// to talk bewteen C and the Lua virtual machine
	std::cout << "[C++] Creating the arg table" << std::endl;
	lua_createtable(lua_state, 2, 0);

	lua_pushnumber(lua_state, 1);
	lua_pushnumber(lua_state, 49);

	lua_settable(lua_state, -3);
	lua_pushnumber(lua_state, 2);
	lua_pushstring(lua_state, "Life is a beach");
	lua_settable(lua_state, -3);

	lua_setglobal(lua_state, "arg");

	// Load the script
	std::cout << "[C++] Loading the Lua script" << std::endl;
	int status = luaL_loadfile(lua_state, "script.lua");
	std::cout << "return: " << status << std::endl;

	// Run the script with the given arguments
	std::cout << "[C++] Running script" << std::endl;
	int result = 0;

	result = lua_pcall(lua_state, 0, LUA_MULTRET, 0);

	// Print the value returned from the script
	std::cout << "[C++] Values returned from the script:" << std::endl;
	std::stringstream str_buf;

	while (lua_gettop(lua_state))
	{
		str_buf << " ";
		switch (lua_type(lua_state, lua_gettop(lua_state)))
		{
		case LUA_TNUMBER:
			str_buf << "\tscript returned a number: "
				<< lua_tonumber(lua_state, lua_gettop(lua_state))
				<< std::endl;
			break;

		case LUA_TTABLE:
			str_buf << "\tscript returned a table" << std::endl;
			break;

		case LUA_TSTRING:
			str_buf << "\tscript returned a string: "
				<< lua_tostring(lua_state, lua_gettop(lua_state))
				<< std::endl;
			break;

		case LUA_TBOOLEAN:
			str_buf << "\tscript returned a boolean: "
				<< lua_toboolean(lua_state, lua_gettop(lua_state))
				<< std::endl;
			break;
		default:
			str_buf << "\tscript returned an unknown-type value"
				<< std::endl;
		}
		lua_pop(lua_state, 1);
	
	}
	std::cout << str_buf.str() << std::endl;
	// Close the Lua State
	std::cout << "[C++] Closing the Lua state" << std::endl;
	return 0;
}*/

int main()
{
	int iErr = 0;
	lua_State *lua_state = lua_open();
	luaL_openlibs(lua_state);

	if ((iErr = luaL_loadfile(lua_state, "test.lua")) == 0)
	{
		// Call main
		if ((iErr = lua_pcall(lua_state, 0, LUA_MULTRET, 0)) == 0)
		{
			// Push function name onto the stack
			lua_pushstring(lua_state, "helloWorld");
			lua_pushstring(lua_state, "goodByeWorld");

			// Function is located in the Global Table
			lua_gettable(lua_state, LUA_GLOBALSINDEX);
			lua_pcall(lua_state, 0, 0, 0);

			// Doing this again will call the helloWorld function
			lua_gettable(lua_state, LUA_GLOBALSINDEX);
			lua_pcall(lua_state, 0, 0, 0);

			//lua_getfield(lua_state, 0, "helloWorld");
						
		}
	}

	lua_close(lua_state);
}