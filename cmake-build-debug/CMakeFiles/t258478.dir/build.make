# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/biubiubiuer/CLionProjects/leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/biubiubiuer/CLionProjects/leetcode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/t258478.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/t258478.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/t258478.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/t258478.dir/flags.make

CMakeFiles/t258478.dir/luogu/t258478.cpp.o: CMakeFiles/t258478.dir/flags.make
CMakeFiles/t258478.dir/luogu/t258478.cpp.o: ../luogu/t258478.cpp
CMakeFiles/t258478.dir/luogu/t258478.cpp.o: CMakeFiles/t258478.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/biubiubiuer/CLionProjects/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/t258478.dir/luogu/t258478.cpp.o"
	/opt/homebrew/Cellar/gcc/11.3.0_2/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/t258478.dir/luogu/t258478.cpp.o -MF CMakeFiles/t258478.dir/luogu/t258478.cpp.o.d -o CMakeFiles/t258478.dir/luogu/t258478.cpp.o -c /Users/biubiubiuer/CLionProjects/leetcode/luogu/t258478.cpp

CMakeFiles/t258478.dir/luogu/t258478.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/t258478.dir/luogu/t258478.cpp.i"
	/opt/homebrew/Cellar/gcc/11.3.0_2/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/biubiubiuer/CLionProjects/leetcode/luogu/t258478.cpp > CMakeFiles/t258478.dir/luogu/t258478.cpp.i

CMakeFiles/t258478.dir/luogu/t258478.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/t258478.dir/luogu/t258478.cpp.s"
	/opt/homebrew/Cellar/gcc/11.3.0_2/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/biubiubiuer/CLionProjects/leetcode/luogu/t258478.cpp -o CMakeFiles/t258478.dir/luogu/t258478.cpp.s

# Object files for target t258478
t258478_OBJECTS = \
"CMakeFiles/t258478.dir/luogu/t258478.cpp.o"

# External object files for target t258478
t258478_EXTERNAL_OBJECTS =

t258478: CMakeFiles/t258478.dir/luogu/t258478.cpp.o
t258478: CMakeFiles/t258478.dir/build.make
t258478: CMakeFiles/t258478.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/biubiubiuer/CLionProjects/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable t258478"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/t258478.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/t258478.dir/build: t258478
.PHONY : CMakeFiles/t258478.dir/build

CMakeFiles/t258478.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/t258478.dir/cmake_clean.cmake
.PHONY : CMakeFiles/t258478.dir/clean

CMakeFiles/t258478.dir/depend:
	cd /Users/biubiubiuer/CLionProjects/leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/biubiubiuer/CLionProjects/leetcode /Users/biubiubiuer/CLionProjects/leetcode /Users/biubiubiuer/CLionProjects/leetcode/cmake-build-debug /Users/biubiubiuer/CLionProjects/leetcode/cmake-build-debug /Users/biubiubiuer/CLionProjects/leetcode/cmake-build-debug/CMakeFiles/t258478.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/t258478.dir/depend

