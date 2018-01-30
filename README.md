# Practice with using Lua inside C++
See link for content followed

https://csl.name/post/lua-and-cpp/
https://eliasdaler.wordpress.com/2013/10/11/lua_cpp_binder/

## Command line help
Run for lua stuff

    g++ -W -Wall -g -o first first.cpp -I/usr/local/include -L/usr/local/lib -llua
    
may need to add -ldl sometimes
