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
CMAKE_SOURCE_DIR = "D:\Coding\BSU\Computer Architecture\Gauss_Generator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Coding\BSU\Computer Architecture\Gauss_Generator\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Gauss_Generator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Gauss_Generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Gauss_Generator.dir/flags.make

CMakeFiles/Gauss_Generator.dir/main.cpp.obj: CMakeFiles/Gauss_Generator.dir/flags.make
CMakeFiles/Gauss_Generator.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Coding\BSU\Computer Architecture\Gauss_Generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Gauss_Generator.dir/main.cpp.obj"
	C:\dev\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Gauss_Generator.dir\main.cpp.obj -c "D:\Coding\BSU\Computer Architecture\Gauss_Generator\main.cpp"

CMakeFiles/Gauss_Generator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gauss_Generator.dir/main.cpp.i"
	C:\dev\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Coding\BSU\Computer Architecture\Gauss_Generator\main.cpp" > CMakeFiles\Gauss_Generator.dir\main.cpp.i

CMakeFiles/Gauss_Generator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gauss_Generator.dir/main.cpp.s"
	C:\dev\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Coding\BSU\Computer Architecture\Gauss_Generator\main.cpp" -o CMakeFiles\Gauss_Generator.dir\main.cpp.s

# Object files for target Gauss_Generator
Gauss_Generator_OBJECTS = \
"CMakeFiles/Gauss_Generator.dir/main.cpp.obj"

# External object files for target Gauss_Generator
Gauss_Generator_EXTERNAL_OBJECTS =

Gauss_Generator.exe: CMakeFiles/Gauss_Generator.dir/main.cpp.obj
Gauss_Generator.exe: CMakeFiles/Gauss_Generator.dir/build.make
Gauss_Generator.exe: CMakeFiles/Gauss_Generator.dir/linklibs.rsp
Gauss_Generator.exe: CMakeFiles/Gauss_Generator.dir/objects1.rsp
Gauss_Generator.exe: CMakeFiles/Gauss_Generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Coding\BSU\Computer Architecture\Gauss_Generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Gauss_Generator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Gauss_Generator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Gauss_Generator.dir/build: Gauss_Generator.exe

.PHONY : CMakeFiles/Gauss_Generator.dir/build

CMakeFiles/Gauss_Generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Gauss_Generator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Gauss_Generator.dir/clean

CMakeFiles/Gauss_Generator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Coding\BSU\Computer Architecture\Gauss_Generator" "D:\Coding\BSU\Computer Architecture\Gauss_Generator" "D:\Coding\BSU\Computer Architecture\Gauss_Generator\cmake-build-debug" "D:\Coding\BSU\Computer Architecture\Gauss_Generator\cmake-build-debug" "D:\Coding\BSU\Computer Architecture\Gauss_Generator\cmake-build-debug\CMakeFiles\Gauss_Generator.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Gauss_Generator.dir/depend

