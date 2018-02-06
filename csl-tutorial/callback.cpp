#include <stdio.h>

#ifdef __cplusplus
# include <lua.hpp>
#else
# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>
#endif


#ifdef __cplusplus
extern "C"
#endif

int howdy(lua_State* state)
{
    int args = lua_gettop(state);
    
    printf("howdy() was called with %d arguments:\n", args);
    
    for( int i = 1; i <= args; ++i)
    {
        printf("arguments %d: '%s' \n", i, lua_tostring(state, i));
    }
    
    // Push the return value on top of the stack. 
    // NOTE: We haven't popped the input arguments to our function. To be hones,
    // I haven't checked if we must, but at least in stack machines like the
    // JVM, the stack will be cleaned between each function call.
    
    // Check this note after
    
    lua_pushnumber(state, 123);
    
    // Let lua know how many return values we've passed
    return 1;
}

void print_error(lua_State* state) {
  // The error message is on top of the stack.
  // Fetch it, print it and then pop it off the stack.
  const char* message = lua_tostring(state, -1);
  puts(message);
  lua_pop(state, 1);
}

void execute(const char* filename)
{
  lua_State *state = luaL_newstate();

  // Make standard libraries available in the Lua object
  luaL_openlibs(state);

  int result;
  
  // Make howdy() available to Lua programs under the same name.
  lua_register(state, "howdy", howdy);

  // Load the program; this supports both source code and bytecode files.
  result = luaL_loadfile(state, filename);

  if ( result != LUA_OK ) {
    print_error(state);
    return;
  }

  // Finally, execute the program by calling into it.
  // Change the arguments if you're not running vanilla Lua code.

  result = lua_pcall(state, 0, LUA_MULTRET, 0);

  if ( result != LUA_OK ) {
    print_error(state);
    return;
  }
}

int main(int argc, char** argv)
{
  if ( argc <= 1 ) {
    puts("Usage: runlua file(s)");
    puts("Loads and executes Lua programs.");
    return 1;
  }

  // Execute all programs on the command line
  for ( int n=1; n<argc; ++n ) {
    execute(argv[n]);
  }

  return 0;
}