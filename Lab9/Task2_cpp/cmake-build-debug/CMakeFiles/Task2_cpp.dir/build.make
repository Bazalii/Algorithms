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
CMAKE_COMMAND = "D:\Ivan\Programming\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Ivan\Programming\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task2_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task2_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task2_cpp.dir/flags.make

CMakeFiles/Task2_cpp.dir/main.cpp.obj: CMakeFiles/Task2_cpp.dir/flags.make
CMakeFiles/Task2_cpp.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task2_cpp.dir/main.cpp.obj"
	D:\Ivan\Programming\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Task2_cpp.dir\main.cpp.obj -c D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp\main.cpp

CMakeFiles/Task2_cpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task2_cpp.dir/main.cpp.i"
	D:\Ivan\Programming\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp\main.cpp > CMakeFiles\Task2_cpp.dir\main.cpp.i

CMakeFiles/Task2_cpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task2_cpp.dir/main.cpp.s"
	D:\Ivan\Programming\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp\main.cpp -o CMakeFiles\Task2_cpp.dir\main.cpp.s

# Object files for target Task2_cpp
Task2_cpp_OBJECTS = \
"CMakeFiles/Task2_cpp.dir/main.cpp.obj"

# External object files for target Task2_cpp
Task2_cpp_EXTERNAL_OBJECTS =

Task2_cpp.exe: CMakeFiles/Task2_cpp.dir/main.cpp.obj
Task2_cpp.exe: CMakeFiles/Task2_cpp.dir/build.make
Task2_cpp.exe: CMakeFiles/Task2_cpp.dir/linklibs.rsp
Task2_cpp.exe: CMakeFiles/Task2_cpp.dir/objects1.rsp
Task2_cpp.exe: CMakeFiles/Task2_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task2_cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task2_cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task2_cpp.dir/build: Task2_cpp.exe

.PHONY : CMakeFiles/Task2_cpp.dir/build

CMakeFiles/Task2_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task2_cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task2_cpp.dir/clean

CMakeFiles/Task2_cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp\cmake-build-debug D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp\cmake-build-debug D:\Ivan\ITMO\Algorithms\Lab9\Task2_cpp\cmake-build-debug\CMakeFiles\Task2_cpp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task2_cpp.dir/depend

