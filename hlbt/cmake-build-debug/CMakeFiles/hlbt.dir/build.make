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
CMAKE_SOURCE_DIR = C:\Users\pinkykiller\CLionProjects\hlbt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pinkykiller\CLionProjects\hlbt\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hlbt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hlbt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hlbt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hlbt.dir/flags.make

CMakeFiles/hlbt.dir/main.c.obj: CMakeFiles/hlbt.dir/flags.make
CMakeFiles/hlbt.dir/main.c.obj: C:/Users/pinkykiller/CLionProjects/hlbt/main.c
CMakeFiles/hlbt.dir/main.c.obj: CMakeFiles/hlbt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pinkykiller\CLionProjects\hlbt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hlbt.dir/main.c.obj"
	E:\stmconfig\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hlbt.dir/main.c.obj -MF CMakeFiles\hlbt.dir\main.c.obj.d -o CMakeFiles\hlbt.dir\main.c.obj -c C:\Users\pinkykiller\CLionProjects\hlbt\main.c

CMakeFiles/hlbt.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hlbt.dir/main.c.i"
	E:\stmconfig\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pinkykiller\CLionProjects\hlbt\main.c > CMakeFiles\hlbt.dir\main.c.i

CMakeFiles/hlbt.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hlbt.dir/main.c.s"
	E:\stmconfig\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pinkykiller\CLionProjects\hlbt\main.c -o CMakeFiles\hlbt.dir\main.c.s

# Object files for target hlbt
hlbt_OBJECTS = \
"CMakeFiles/hlbt.dir/main.c.obj"

# External object files for target hlbt
hlbt_EXTERNAL_OBJECTS =

hlbt.exe: CMakeFiles/hlbt.dir/main.c.obj
hlbt.exe: CMakeFiles/hlbt.dir/build.make
hlbt.exe: CMakeFiles/hlbt.dir/linkLibs.rsp
hlbt.exe: CMakeFiles/hlbt.dir/objects1
hlbt.exe: CMakeFiles/hlbt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\pinkykiller\CLionProjects\hlbt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable hlbt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hlbt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hlbt.dir/build: hlbt.exe
.PHONY : CMakeFiles/hlbt.dir/build

CMakeFiles/hlbt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hlbt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hlbt.dir/clean

CMakeFiles/hlbt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pinkykiller\CLionProjects\hlbt C:\Users\pinkykiller\CLionProjects\hlbt C:\Users\pinkykiller\CLionProjects\hlbt\cmake-build-debug C:\Users\pinkykiller\CLionProjects\hlbt\cmake-build-debug C:\Users\pinkykiller\CLionProjects\hlbt\cmake-build-debug\CMakeFiles\hlbt.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hlbt.dir/depend

