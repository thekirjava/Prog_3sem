# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Coding\BSU\Computere Architecture\Lab1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Coding\BSU\Computere Architecture\Lab1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab1.dir/flags.make

CMakeFiles/Lab1.dir/main.c.obj: CMakeFiles/Lab1.dir/flags.make
CMakeFiles/Lab1.dir/main.c.obj: CMakeFiles/Lab1.dir/includes_C.rsp
CMakeFiles/Lab1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Coding\BSU\Computere Architecture\Lab1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab1.dir/main.c.obj"
	C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Lab1.dir\main.c.obj   -c "D:\Coding\BSU\Computere Architecture\Lab1\main.c"

CMakeFiles/Lab1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab1.dir/main.c.i"
	C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Coding\BSU\Computere Architecture\Lab1\main.c" > CMakeFiles\Lab1.dir\main.c.i

CMakeFiles/Lab1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab1.dir/main.c.s"
	C:\dev\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Coding\BSU\Computere Architecture\Lab1\main.c" -o CMakeFiles\Lab1.dir\main.c.s

# Object files for target Lab1
Lab1_OBJECTS = \
"CMakeFiles/Lab1.dir/main.c.obj"

# External object files for target Lab1
Lab1_EXTERNAL_OBJECTS =

Lab1.exe: CMakeFiles/Lab1.dir/main.c.obj
Lab1.exe: CMakeFiles/Lab1.dir/build.make
Lab1.exe: C:/Program\ Files\ (x86)/Microsoft\ SDKs/MPI/Lib/x64/msmpi.lib
Lab1.exe: CMakeFiles/Lab1.dir/linklibs.rsp
Lab1.exe: CMakeFiles/Lab1.dir/objects1.rsp
Lab1.exe: CMakeFiles/Lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Coding\BSU\Computere Architecture\Lab1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lab1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab1.dir/build: Lab1.exe

.PHONY : CMakeFiles/Lab1.dir/build

CMakeFiles/Lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab1.dir/clean

CMakeFiles/Lab1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Coding\BSU\Computere Architecture\Lab1" "D:\Coding\BSU\Computere Architecture\Lab1" "D:\Coding\BSU\Computere Architecture\Lab1\cmake-build-debug" "D:\Coding\BSU\Computere Architecture\Lab1\cmake-build-debug" "D:\Coding\BSU\Computere Architecture\Lab1\cmake-build-debug\CMakeFiles\Lab1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab1.dir/depend

