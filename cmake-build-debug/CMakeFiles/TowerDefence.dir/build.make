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
CMAKE_COMMAND = /home/mike/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mike/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7223.86/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mike/PA2/TowerDefence

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mike/PA2/TowerDefence/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TowerDefence.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TowerDefence.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TowerDefence.dir/flags.make

CMakeFiles/TowerDefence.dir/src/main.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mike/PA2/TowerDefence/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TowerDefence.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TowerDefence.dir/src/main.cpp.o -c /home/mike/PA2/TowerDefence/src/main.cpp

CMakeFiles/TowerDefence.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mike/PA2/TowerDefence/src/main.cpp > CMakeFiles/TowerDefence.dir/src/main.cpp.i

CMakeFiles/TowerDefence.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mike/PA2/TowerDefence/src/main.cpp -o CMakeFiles/TowerDefence.dir/src/main.cpp.s

CMakeFiles/TowerDefence.dir/src/CMap.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/CMap.cpp.o: ../src/CMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mike/PA2/TowerDefence/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TowerDefence.dir/src/CMap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TowerDefence.dir/src/CMap.cpp.o -c /home/mike/PA2/TowerDefence/src/CMap.cpp

CMakeFiles/TowerDefence.dir/src/CMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/CMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mike/PA2/TowerDefence/src/CMap.cpp > CMakeFiles/TowerDefence.dir/src/CMap.cpp.i

CMakeFiles/TowerDefence.dir/src/CMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/CMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mike/PA2/TowerDefence/src/CMap.cpp -o CMakeFiles/TowerDefence.dir/src/CMap.cpp.s

CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.o: ../src/CEnemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mike/PA2/TowerDefence/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.o -c /home/mike/PA2/TowerDefence/src/CEnemy.cpp

CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mike/PA2/TowerDefence/src/CEnemy.cpp > CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.i

CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mike/PA2/TowerDefence/src/CEnemy.cpp -o CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.s

CMakeFiles/TowerDefence.dir/src/CRoute.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/CRoute.cpp.o: ../src/CRoute.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mike/PA2/TowerDefence/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TowerDefence.dir/src/CRoute.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TowerDefence.dir/src/CRoute.cpp.o -c /home/mike/PA2/TowerDefence/src/CRoute.cpp

CMakeFiles/TowerDefence.dir/src/CRoute.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/CRoute.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mike/PA2/TowerDefence/src/CRoute.cpp > CMakeFiles/TowerDefence.dir/src/CRoute.cpp.i

CMakeFiles/TowerDefence.dir/src/CRoute.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/CRoute.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mike/PA2/TowerDefence/src/CRoute.cpp -o CMakeFiles/TowerDefence.dir/src/CRoute.cpp.s

# Object files for target TowerDefence
TowerDefence_OBJECTS = \
"CMakeFiles/TowerDefence.dir/src/main.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/CMap.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/CRoute.cpp.o"

# External object files for target TowerDefence
TowerDefence_EXTERNAL_OBJECTS =

TowerDefence: CMakeFiles/TowerDefence.dir/src/main.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/CMap.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/CEnemy.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/CRoute.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/build.make
TowerDefence: CMakeFiles/TowerDefence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mike/PA2/TowerDefence/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable TowerDefence"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TowerDefence.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TowerDefence.dir/build: TowerDefence

.PHONY : CMakeFiles/TowerDefence.dir/build

CMakeFiles/TowerDefence.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TowerDefence.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TowerDefence.dir/clean

CMakeFiles/TowerDefence.dir/depend:
	cd /home/mike/PA2/TowerDefence/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mike/PA2/TowerDefence /home/mike/PA2/TowerDefence /home/mike/PA2/TowerDefence/cmake-build-debug /home/mike/PA2/TowerDefence/cmake-build-debug /home/mike/PA2/TowerDefence/cmake-build-debug/CMakeFiles/TowerDefence.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TowerDefence.dir/depend

