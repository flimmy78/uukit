# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/uukit/DoorBell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/uukit/DoorBell/build

# Include any dependencies generated for this target.
include CMakeFiles/test_hwsdkc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_hwsdkc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_hwsdkc.dir/flags.make

CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o: CMakeFiles/test_hwsdkc.dir/flags.make
CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o: ../test_hwsdk.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/uukit/DoorBell/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o -c /root/uukit/DoorBell/test_hwsdk.cpp

CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/uukit/DoorBell/test_hwsdk.cpp > CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.i

CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/uukit/DoorBell/test_hwsdk.cpp -o CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.s

CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o.requires:
.PHONY : CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o.requires

CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o.provides: CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_hwsdkc.dir/build.make CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o.provides.build
.PHONY : CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o.provides

CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o.provides.build: CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o

# Object files for target test_hwsdkc
test_hwsdkc_OBJECTS = \
"CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o"

# External object files for target test_hwsdkc
test_hwsdkc_EXTERNAL_OBJECTS =

test_hwsdkc: CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o
test_hwsdkc: CMakeFiles/test_hwsdkc.dir/build.make
test_hwsdkc: CMakeFiles/test_hwsdkc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test_hwsdkc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_hwsdkc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_hwsdkc.dir/build: test_hwsdkc
.PHONY : CMakeFiles/test_hwsdkc.dir/build

CMakeFiles/test_hwsdkc.dir/requires: CMakeFiles/test_hwsdkc.dir/test_hwsdk.cpp.o.requires
.PHONY : CMakeFiles/test_hwsdkc.dir/requires

CMakeFiles/test_hwsdkc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_hwsdkc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_hwsdkc.dir/clean

CMakeFiles/test_hwsdkc.dir/depend:
	cd /root/uukit/DoorBell/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/uukit/DoorBell /root/uukit/DoorBell /root/uukit/DoorBell/build /root/uukit/DoorBell/build /root/uukit/DoorBell/build/CMakeFiles/test_hwsdkc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_hwsdkc.dir/depend

