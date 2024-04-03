# Why am I not using Make?
# 1.)   I want total control over the system. 
#       Occassionally I want to have some logic
#       in my compilation process.
# 2.)   Realistically our projects are 'small' enough 
#       this will not matter.
# 3.)   Feel free to implement your own make files.
# 4.)   It is handy to know Python


# import os

# Compiler settings
COMPILER = "g++"
SOURCE = "./src/*.cpp"

# Compiler arguments
ARGUMENTS = "-std=c++17 -shared -undefined dynamic_lookup"

# Include directories
INCLUDE_DIR = ("-I ./include/ "
               "-I ./pybind11/include/ "
               "-I /usr/local/opt/sdl2/include/SDL2 " 
               "-I /Library/Frameworks/Python.framework/Versions/3.11/include/python3.11")

# Libraries to include
LIBRARIES = ("-L /usr/local/opt/sdl2/lib "
             "-l SDL2 "
             "`python3.11-config --ldflags`")

# Executable output
EXECUTABLE = "mygameengine.so"

# Build the compile command
compile_command = (
    f"{COMPILER} {ARGUMENTS} -o {EXECUTABLE} {INCLUDE_DIR} {SOURCE} {LIBRARIES}"
)

# Print the compile command for debugging
print("Compile command:", compile_command)

# Execute the compile command
os.system(compile_command)


