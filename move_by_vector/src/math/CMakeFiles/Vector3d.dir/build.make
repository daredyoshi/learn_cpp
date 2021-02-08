# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/dev/learn_cpp/move_by_vector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/dev/learn_cpp/move_by_vector

# Include any dependencies generated for this target.
include src/math/CMakeFiles/Vector3d.dir/depend.make

# Include the progress variables for this target.
include src/math/CMakeFiles/Vector3d.dir/progress.make

# Include the compile flags for this target's objects.
include src/math/CMakeFiles/Vector3d.dir/flags.make

src/math/CMakeFiles/Vector3d.dir/Vector3d.cpp.o: src/math/CMakeFiles/Vector3d.dir/flags.make
src/math/CMakeFiles/Vector3d.dir/Vector3d.cpp.o: src/math/Vector3d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/dev/learn_cpp/move_by_vector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/math/CMakeFiles/Vector3d.dir/Vector3d.cpp.o"
	cd /media/dev/learn_cpp/move_by_vector/src/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vector3d.dir/Vector3d.cpp.o -c /media/dev/learn_cpp/move_by_vector/src/math/Vector3d.cpp

src/math/CMakeFiles/Vector3d.dir/Vector3d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vector3d.dir/Vector3d.cpp.i"
	cd /media/dev/learn_cpp/move_by_vector/src/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/dev/learn_cpp/move_by_vector/src/math/Vector3d.cpp > CMakeFiles/Vector3d.dir/Vector3d.cpp.i

src/math/CMakeFiles/Vector3d.dir/Vector3d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vector3d.dir/Vector3d.cpp.s"
	cd /media/dev/learn_cpp/move_by_vector/src/math && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/dev/learn_cpp/move_by_vector/src/math/Vector3d.cpp -o CMakeFiles/Vector3d.dir/Vector3d.cpp.s

# Object files for target Vector3d
Vector3d_OBJECTS = \
"CMakeFiles/Vector3d.dir/Vector3d.cpp.o"

# External object files for target Vector3d
Vector3d_EXTERNAL_OBJECTS =

src/math/libVector3d.so: src/math/CMakeFiles/Vector3d.dir/Vector3d.cpp.o
src/math/libVector3d.so: src/math/CMakeFiles/Vector3d.dir/build.make
src/math/libVector3d.so: src/math/CMakeFiles/Vector3d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/dev/learn_cpp/move_by_vector/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libVector3d.so"
	cd /media/dev/learn_cpp/move_by_vector/src/math && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vector3d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/math/CMakeFiles/Vector3d.dir/build: src/math/libVector3d.so

.PHONY : src/math/CMakeFiles/Vector3d.dir/build

src/math/CMakeFiles/Vector3d.dir/clean:
	cd /media/dev/learn_cpp/move_by_vector/src/math && $(CMAKE_COMMAND) -P CMakeFiles/Vector3d.dir/cmake_clean.cmake
.PHONY : src/math/CMakeFiles/Vector3d.dir/clean

src/math/CMakeFiles/Vector3d.dir/depend:
	cd /media/dev/learn_cpp/move_by_vector && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/dev/learn_cpp/move_by_vector /media/dev/learn_cpp/move_by_vector/src/math /media/dev/learn_cpp/move_by_vector /media/dev/learn_cpp/move_by_vector/src/math /media/dev/learn_cpp/move_by_vector/src/math/CMakeFiles/Vector3d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/math/CMakeFiles/Vector3d.dir/depend

