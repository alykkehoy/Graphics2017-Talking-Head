# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Anders\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\172.3968.17\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Anders\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\172.3968.17\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Anders\CLionProjects\OpenGLPractice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Anders\CLionProjects\OpenGLPractice\cmake-build-debug

# Utility rule file for uninstall.

# Include the progress variables for this target.
include glfw/CMakeFiles/uninstall.dir/progress.make

glfw/CMakeFiles/uninstall:
	cd /d C:\Users\Anders\CLionProjects\OpenGLPractice\cmake-build-debug\glfw && C:\Users\Anders\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\172.3968.17\bin\cmake\bin\cmake.exe -P C:/Users/Anders/CLionProjects/OpenGLPractice/cmake-build-debug/glfw/cmake_uninstall.cmake

uninstall: glfw/CMakeFiles/uninstall
uninstall: glfw/CMakeFiles/uninstall.dir/build.make

.PHONY : uninstall

# Rule to build all files generated by this target.
glfw/CMakeFiles/uninstall.dir/build: uninstall

.PHONY : glfw/CMakeFiles/uninstall.dir/build

glfw/CMakeFiles/uninstall.dir/clean:
	cd /d C:\Users\Anders\CLionProjects\OpenGLPractice\cmake-build-debug\glfw && $(CMAKE_COMMAND) -P CMakeFiles\uninstall.dir\cmake_clean.cmake
.PHONY : glfw/CMakeFiles/uninstall.dir/clean

glfw/CMakeFiles/uninstall.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Anders\CLionProjects\OpenGLPractice C:\Users\Anders\CLionProjects\OpenGLPractice\glfw C:\Users\Anders\CLionProjects\OpenGLPractice\cmake-build-debug C:\Users\Anders\CLionProjects\OpenGLPractice\cmake-build-debug\glfw C:\Users\Anders\CLionProjects\OpenGLPractice\cmake-build-debug\glfw\CMakeFiles\uninstall.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : glfw/CMakeFiles/uninstall.dir/depend

