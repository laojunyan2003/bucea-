# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pinkykiller\CLionProjects\paixu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pinkykiller\CLionProjects\paixu\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/paixu.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/paixu.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/paixu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/paixu.dir/flags.make

CMakeFiles/paixu.dir/main.cpp.obj: CMakeFiles/paixu.dir/flags.make
CMakeFiles/paixu.dir/main.cpp.obj: C:/Users/pinkykiller/CLionProjects/paixu/main.cpp
CMakeFiles/paixu.dir/main.cpp.obj: CMakeFiles/paixu.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pinkykiller\CLionProjects\paixu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/paixu.dir/main.cpp.obj"
	E:\stmconfig\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/paixu.dir/main.cpp.obj -MF CMakeFiles\paixu.dir\main.cpp.obj.d -o CMakeFiles\paixu.dir\main.cpp.obj -c C:\Users\pinkykiller\CLionProjects\paixu\main.cpp

CMakeFiles/paixu.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paixu.dir/main.cpp.i"
	E:\stmconfig\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pinkykiller\CLionProjects\paixu\main.cpp > CMakeFiles\paixu.dir\main.cpp.i

CMakeFiles/paixu.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paixu.dir/main.cpp.s"
	E:\stmconfig\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pinkykiller\CLionProjects\paixu\main.cpp -o CMakeFiles\paixu.dir\main.cpp.s

# Object files for target paixu
paixu_OBJECTS = \
"CMakeFiles/paixu.dir/main.cpp.obj"

# External object files for target paixu
paixu_EXTERNAL_OBJECTS =

paixu.exe: CMakeFiles/paixu.dir/main.cpp.obj
paixu.exe: CMakeFiles/paixu.dir/build.make
paixu.exe: CMakeFiles/paixu.dir/linkLibs.rsp
paixu.exe: CMakeFiles/paixu.dir/objects1
paixu.exe: CMakeFiles/paixu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\pinkykiller\CLionProjects\paixu\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable paixu.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\paixu.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/paixu.dir/build: paixu.exe
.PHONY : CMakeFiles/paixu.dir/build

CMakeFiles/paixu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\paixu.dir\cmake_clean.cmake
.PHONY : CMakeFiles/paixu.dir/clean

CMakeFiles/paixu.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pinkykiller\CLionProjects\paixu C:\Users\pinkykiller\CLionProjects\paixu C:\Users\pinkykiller\CLionProjects\paixu\cmake-build-debug C:\Users\pinkykiller\CLionProjects\paixu\cmake-build-debug C:\Users\pinkykiller\CLionProjects\paixu\cmake-build-debug\CMakeFiles\paixu.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/paixu.dir/depend

