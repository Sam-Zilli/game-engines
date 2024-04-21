import os
import sys

# Compiler settings
COMPILER = "g++"
SOURCE = "../src/*.cpp"

# Compiler arguments
ARGUMENTS = "-std=c++20 -shared -undefined dynamic_lookup -g -Wall -Werror"

# Include directories
INCLUDE_DIR = ("-I ../include/ "
               "-I ./pybind11/include/ "
               "-I /Library/Frameworks/Python.framework/Versions/3.11/include/python3.11 "
               "-I ../assets/")



import os
import sys

# Compiler settings
COMPILER = "g++"
SOURCE = "../src/*.cpp"

# Compiler arguments
ARGUMENTS = "-std=c++20 -shared -undefined dynamic_lookup -g -Wall -Werror"

# Include directories
INCLUDE_DIR = ("-I ../include/ "
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