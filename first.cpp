#ifdef __cplusplus
# include <lua.hpp>
#else
# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>
#endif

int main()
{
  lua_State *state = luaL_newstate();
  
  luaL_dofile(state, "lua_src/hello.lua");
  
  lua_close(state);
  return 0;
}
// Use this site
// https://csl.name/post/lua-and-cpp/
// https://eliasdaler.wordpress.com/2013/10/11/lua_cpp_binder/