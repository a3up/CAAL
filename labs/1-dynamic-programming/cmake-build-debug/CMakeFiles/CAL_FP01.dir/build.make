# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/a3brx/Studies/caal/labs/1-dynamic-programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CAL_FP01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CAL_FP01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CAL_FP01.dir/flags.make

CMakeFiles/CAL_FP01.dir/main.cpp.o: CMakeFiles/CAL_FP01.dir/flags.make
CMakeFiles/CAL_FP01.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CAL_FP01.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CAL_FP01.dir/main.cpp.o -c /home/a3brx/Studies/caal/labs/1-dynamic-programming/main.cpp

CMakeFiles/CAL_FP01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAL_FP01.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/a3brx/Studies/caal/labs/1-dynamic-programming/main.cpp > CMakeFiles/CAL_FP01.dir/main.cpp.i

CMakeFiles/CAL_FP01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAL_FP01.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/a3brx/Studies/caal/labs/1-dynamic-programming/main.cpp -o CMakeFiles/CAL_FP01.dir/main.cpp.s

CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.o: CMakeFiles/CAL_FP01.dir/flags.make
CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.o: ../Tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.o -c /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/tests.cpp

CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/tests.cpp > CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.i

CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/tests.cpp -o CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.s

CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.o: CMakeFiles/CAL_FP01.dir/flags.make
CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.o: ../Tests/Change.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.o -c /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Change.cpp

CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Change.cpp > CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.i

CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Change.cpp -o CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.s

CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.o: CMakeFiles/CAL_FP01.dir/flags.make
CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.o: ../Tests/Factorial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.o -c /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Factorial.cpp

CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Factorial.cpp > CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.i

CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Factorial.cpp -o CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.s

CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.o: CMakeFiles/CAL_FP01.dir/flags.make
CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.o: ../Tests/Partitioning.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.o -c /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Partitioning.cpp

CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Partitioning.cpp > CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.i

CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Partitioning.cpp -o CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.s

CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.o: CMakeFiles/CAL_FP01.dir/flags.make
CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.o: ../Tests/Sum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.o -c /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Sum.cpp

CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Sum.cpp > CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.i

CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/a3brx/Studies/caal/labs/1-dynamic-programming/Tests/Sum.cpp -o CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.s

# Object files for target CAL_FP01
CAL_FP01_OBJECTS = \
"CMakeFiles/CAL_FP01.dir/main.cpp.o" \
"CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.o" \
"CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.o" \
"CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.o" \
"CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.o" \
"CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.o"

# External object files for target CAL_FP01
CAL_FP01_EXTERNAL_OBJECTS =

CAL_FP01: CMakeFiles/CAL_FP01.dir/main.cpp.o
CAL_FP01: CMakeFiles/CAL_FP01.dir/Tests/tests.cpp.o
CAL_FP01: CMakeFiles/CAL_FP01.dir/Tests/Change.cpp.o
CAL_FP01: CMakeFiles/CAL_FP01.dir/Tests/Factorial.cpp.o
CAL_FP01: CMakeFiles/CAL_FP01.dir/Tests/Partitioning.cpp.o
CAL_FP01: CMakeFiles/CAL_FP01.dir/Tests/Sum.cpp.o
CAL_FP01: CMakeFiles/CAL_FP01.dir/build.make
CAL_FP01: lib/libgtestd.a
CAL_FP01: lib/libgtest_maind.a
CAL_FP01: lib/libgtestd.a
CAL_FP01: CMakeFiles/CAL_FP01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable CAL_FP01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CAL_FP01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CAL_FP01.dir/build: CAL_FP01

.PHONY : CMakeFiles/CAL_FP01.dir/build

CMakeFiles/CAL_FP01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CAL_FP01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CAL_FP01.dir/clean

CMakeFiles/CAL_FP01.dir/depend:
	cd /home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/a3brx/Studies/caal/labs/1-dynamic-programming /home/a3brx/Studies/caal/labs/1-dynamic-programming /home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug /home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug /home/a3brx/Studies/caal/labs/1-dynamic-programming/cmake-build-debug/CMakeFiles/CAL_FP01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CAL_FP01.dir/depend

