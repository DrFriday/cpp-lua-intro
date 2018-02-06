-- print the arguments passed from C
io.write("[Lua] These args were passed into the script from C")
for i=1,#arg do
    print("\n      ", i, arg[i])
end 
-- return a value of different Lua types (boolean, table, numeric, string)
io.write("[Lua] Script returning data back to C\n")

-- create the table
local temp = {}
temp[1]=9
temp[2]="See you space cowboy!"

return true , temp, 21, "I am a mushroom"