--[[] Code Used with UsingLuaInCpp.cpp #1
function helloPerson (name)
   io.write("Hello ", name, "!\n")
end

print("What's our name?")

name = io.read()

helloPerson(name)

io.write("Are you doing fine?\n")

--A test code below
tree = {
	GraphicsComponent = {
		fileName = "res/images/tree.png",
		z = 0,
		animated = false,
		frame = {64, 0, 64, 74}
	},
	CollisionCompontent = {
		type = "Solid",
		boundingBox = {14, 60, 32, 10}
	}
}]]

-- Lua Hello World (test.lua)
function helloWorld()
	io.write("Hello World!\n")
end

function goodByeWorld()
	io.write("Good Bye World!\n")
end