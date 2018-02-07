#include <iostream>
#ifdef __cplusplus
# include <lua.hpp>
#else
# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>
#endif

#include <string>


int main()
{
    std::cout << "Hello" << std::endl;
    LuaScript script("hello.lua");
    
    std::string filename = script.get("player.filename");
    std::cout << "File name is: " << std::endl;
    return 0;
}
