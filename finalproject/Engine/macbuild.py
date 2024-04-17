# Why am I not using Make?
# 1.)   I want total control over the system. 
#       Occassionally I want to have some logic
#       in my compilation process.
# 2.)   Realistically our projects are 'small' enough 
#       this will not matter.
# 3.)   Feel free to implement your own make files.
# 4.)   It is handy to know Python


# import os

# COMPILER="g++"

# SOURCE="./src/*.cpp"

# # You can can add other arguments as you see fit.
# # What does the "-D MAC" command do? 
# ARGUMENTS="-D MAC -std=c++17 -shared -undefined dynamic_lookup" 

# # Which directories do we want to include.
# # INCLUDE_DIR="-I ./include/ -I./pybind11/include/ -I/Library/Frameworks/SDL2.framework/Headers `python3.9 -m pybind11 --includes`"
# # INCLUDE_DIR="-I ./include/ -I./pybind11/include/ -I/Library/Frameworks/SDL2.framework/Headers `python3.11 -m pybind11 --includes`"

# INCLUDE_DIR="-I ./include/ -I./pybind11/include/ -I/usr/local/Cellar/sdl2/2.30.2/include/ `python3.11 -m pybind11 --includes`"

# # What libraries do we want to include
# LIBRARIES="-F/Library/Frameworks -framework SDL2 `python3.9-config --ldflags`"
# # LIBRARIES="`pkg-config --libs --cflags sdl3` `python3.9-config --ldflags`"
# # LIBRARIES="`pkg-config --libs --cflags sdl3` `python3.11-config --ldflags`"

# # The name of our executable
# EXECUTABLE="mygameengine.so"

# # Build a string of our compile commands that we run in the terminal
# compileString=COMPILER+" "+ARGUMENTS+" -o "+EXECUTABLE+" "+" "+INCLUDE_DIR+" "+SOURCE+" "+LIBRARIES

# # Print out the compile string
# print(compileString)

# # Run our command
# os.system(compileString)






# import os
# import subprocess


# pybind11_include_flags = subprocess.run(["python3.11", "-m", "pybind11", "--includes"], capture_output=True, text=True).stdout.strip()


# # Compiler include directories
# INCLUDE_DIR = ("-I ./include/ "
#                "-I ./pybind11/include/ "
#                f"{pybind11_include_flags} "
#                "-I /usr/local/Cellar/sdl2/2.30.2/include")


# COMPILER = "g++"
# SOURCE = "./src/*.cpp"

# # Compiler arguments
# ARGUMENTS = "-std=c++17 -shared -undefined dynamic_lookup"

# # INCLUDE_DIR = ("-I ./include/ "
# #                "-I ./pybind11/include/ "
# #                "-I /usr/local/Cellar/sdl2/2.30.2/include "
# #                "`python3.11 -m pybind11 --includes`")


# # Libraries to include
# LIBRARIES = ("-F /usr/local/Cellar/sdl2/2.30.2/lib "
#              "-framework SDL2 "
#              "`python3.11-config --ldflags`")

# # Executable output
# EXECUTABLE = "mygameengine.so"

# # Build the compile command
# compile_command = (
#     f"{COMPILER} {ARGUMENTS} -o {EXECUTABLE} {INCLUDE_DIR} {SOURCE} {LIBRARIES}"
# )

# # Print the compile command for debugging
# print("Compile command:", compile_command)

# # Execute the compile command
# os.system(compile_command)


# import os
# import subprocess

# # Get the include flags for pybind11 using subprocess module
# pybind11_include_flags = subprocess.run(["python3.11", "-m", "pybind11", "--includes"], capture_output=True, text=True).stdout.strip()

# # Compiler include directories
# INCLUDE_DIR = ("-I ./include/ "
#                "-I ./pybind11/include/ "
#                f"{pybind11_include_flags} "
#                "-I /usr/local/Cellar/sdl2/2.30.2/include/SDL2 "
#                "-I /Library/Frameworks/Python.framework/Versions/3.11/include/python3.11")

# # Libraries to include
# LIBRARIES = ("-F /usr/local/Cellar/sdl2/2.30.2/lib "
#              "-framework SDL2 "
#              "`python3.11-config --ldflags`")

# # Compiler settings
# COMPILER = "g++"
# SOURCE = "./src/*.cpp"

# # Compiler arguments
# ARGUMENTS = "-std=c++17 -shared -undefined dynamic_lookup"

# # Executable output
# EXECUTABLE = "mygameengine.so"

# # Build the compile command
# compile_command = (
#     f"{COMPILER} {ARGUMENTS} -o {EXECUTABLE} {INCLUDE_DIR} {SOURCE} {LIBRARIES}"
# )

# # Print the compile command for debugging
# print("Compile command:", compile_command)

# # Execute the compile command
# os.system(compile_command)






# import os

# # Compiler settings
# COMPILER = "g++"
# SOURCE = "./src/*.cpp"

# # Compiler arguments
# ARGUMENTS = "-std=c++17 -shared -undefined dynamic_lookup"

# # Include directories
# INCLUDE_DIR = ("-I ./include/ "
#                "-I ./pybind11/include/ "
#                "-I /usr/local/Cellar/sdl2/2.30.2/include/SDL2 "
#                "-I /Library/Frameworks/Python.framework/Versions/3.11/include/python3.11")

# # Libraries to include
# LIBRARIES = ("-F /usr/local/Cellar/sdl2/2.30.2/lib "
#              "-framework SDL2 "
#              "`python3.11-config --ldflags`")

# # Executable output
# EXECUTABLE = "mygameengine.so"

# # Build the compile command
# compile_command = (
#     f"{COMPILER} {ARGUMENTS} -o {EXECUTABLE} {INCLUDE_DIR} {SOURCE} {LIBRARIES}"
# )

# # Print the compile command for debugging
# print("Compile command:", compile_command)

# # Execute the compile command
# os.system(compile_command)


# ------------------- BEFORE CHANGING TO SDL3
# import os

# # Compiler settings
# COMPILER = "g++"
# SOURCE = "./src/*.cpp"

# # Compiler arguments
# ARGUMENTS = "-std=c+20 -shared -undefined dynamic_lookup"

# # Include directories
# INCLUDE_DIR = ("-I ./include/ "
#                "-I ./pybind11/include/ "
#                "-I /usr/local/opt/sdl2/include/SDL2 "  # Adjust path if needed
#                "-I /Library/Frameworks/Python.framework/Versions/3.11/include/python3.11")

# # Libraries to include
# LIBRARIES = ("-L /usr/local/opt/sdl2/lib "
#              "-l SDL2 "
#              "`python3.11-config --ldflags`")

# # Executable output
# EXECUTABLE = "mygameengine.so"

# # Build the compile command
# compile_command = (
#     f"{COMPILER} {ARGUMENTS} -o {EXECUTABLE} {INCLUDE_DIR} {SOURCE} {LIBRARIES}"
# )

# # Print the compile command for debugging
# print("Compile command:", compile_command)

# # Execute the compile command
# os.system(compile_command)


import os
import sys

# Compiler settings
COMPILER = "g++"
SOURCE = "./src/*.cpp"

# Compiler arguments
ARGUMENTS = "-std=c++20 -shared -undefined dynamic_lookup"

# Include directories
INCLUDE_DIR = ("-I ./include/ "
               "-I ./pybind11/include/ "
               "-I /Library/Frameworks/Python.framework/Versions/3.11/include/python3.11")

# # Libraries to include
# LIBRARIES = "`python3.11-config --ldflags`"
LIBRARIES = ("-l SDL3 "                 # Adjust library name if necessary
             f"-I ~/Desktop/GameEngines/sdl3/SDL/include "
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
result = os.system(compile_command)

# Check the result
if result != 0:
    print("Compilation failed.")
    sys.exit(1)  # Exit with error status
else:
    print("Compilation successful.")
    # Add the install_name_tool command
    install_name_tool_command = f"install_name_tool -add_rpath /Users/sam/Desktop/GameEngines/sdl3/sdl_build ./{EXECUTABLE}"
    os.system(install_name_tool_command)
    print("install_name_tool command executed successfully.")
