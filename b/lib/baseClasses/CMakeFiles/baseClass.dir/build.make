# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/kmccormi/sfuhome/tmp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kmccormi/sfuhome/tmp/b

# Include any dependencies generated for this target.
include lib/baseClasses/CMakeFiles/baseClass.dir/depend.make

# Include the progress variables for this target.
include lib/baseClasses/CMakeFiles/baseClass.dir/progress.make

# Include the compile flags for this target's objects.
include lib/baseClasses/CMakeFiles/baseClass.dir/flags.make

lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o: lib/baseClasses/CMakeFiles/baseClass.dir/flags.make
lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o: ../lib/baseClasses/room.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kmccormi/sfuhome/tmp/b/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o"
	cd /home/kmccormi/sfuhome/tmp/b/lib/baseClasses && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/baseClass.dir/room.cpp.o -c /home/kmccormi/sfuhome/tmp/lib/baseClasses/room.cpp

lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseClass.dir/room.cpp.i"
	cd /home/kmccormi/sfuhome/tmp/b/lib/baseClasses && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kmccormi/sfuhome/tmp/lib/baseClasses/room.cpp > CMakeFiles/baseClass.dir/room.cpp.i

lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseClass.dir/room.cpp.s"
	cd /home/kmccormi/sfuhome/tmp/b/lib/baseClasses && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kmccormi/sfuhome/tmp/lib/baseClasses/room.cpp -o CMakeFiles/baseClass.dir/room.cpp.s

lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o.requires:
.PHONY : lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o.requires

lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o.provides: lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o.requires
	$(MAKE) -f lib/baseClasses/CMakeFiles/baseClass.dir/build.make lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o.provides.build
.PHONY : lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o.provides

lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o.provides.build: lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o

lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o: lib/baseClasses/CMakeFiles/baseClass.dir/flags.make
lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o: ../lib/baseClasses/door.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kmccormi/sfuhome/tmp/b/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o"
	cd /home/kmccormi/sfuhome/tmp/b/lib/baseClasses && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/baseClass.dir/door.cpp.o -c /home/kmccormi/sfuhome/tmp/lib/baseClasses/door.cpp

lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/baseClass.dir/door.cpp.i"
	cd /home/kmccormi/sfuhome/tmp/b/lib/baseClasses && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kmccormi/sfuhome/tmp/lib/baseClasses/door.cpp > CMakeFiles/baseClass.dir/door.cpp.i

lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/baseClass.dir/door.cpp.s"
	cd /home/kmccormi/sfuhome/tmp/b/lib/baseClasses && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kmccormi/sfuhome/tmp/lib/baseClasses/door.cpp -o CMakeFiles/baseClass.dir/door.cpp.s

lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o.requires:
.PHONY : lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o.requires

lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o.provides: lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o.requires
	$(MAKE) -f lib/baseClasses/CMakeFiles/baseClass.dir/build.make lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o.provides.build
.PHONY : lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o.provides

lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o.provides.build: lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o

# Object files for target baseClass
baseClass_OBJECTS = \
"CMakeFiles/baseClass.dir/room.cpp.o" \
"CMakeFiles/baseClass.dir/door.cpp.o"

# External object files for target baseClass
baseClass_EXTERNAL_OBJECTS =

lib/libbaseClass.a: lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o
lib/libbaseClass.a: lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o
lib/libbaseClass.a: lib/baseClasses/CMakeFiles/baseClass.dir/build.make
lib/libbaseClass.a: lib/baseClasses/CMakeFiles/baseClass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../libbaseClass.a"
	cd /home/kmccormi/sfuhome/tmp/b/lib/baseClasses && $(CMAKE_COMMAND) -P CMakeFiles/baseClass.dir/cmake_clean_target.cmake
	cd /home/kmccormi/sfuhome/tmp/b/lib/baseClasses && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/baseClass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/baseClasses/CMakeFiles/baseClass.dir/build: lib/libbaseClass.a
.PHONY : lib/baseClasses/CMakeFiles/baseClass.dir/build

lib/baseClasses/CMakeFiles/baseClass.dir/requires: lib/baseClasses/CMakeFiles/baseClass.dir/room.cpp.o.requires
lib/baseClasses/CMakeFiles/baseClass.dir/requires: lib/baseClasses/CMakeFiles/baseClass.dir/door.cpp.o.requires
.PHONY : lib/baseClasses/CMakeFiles/baseClass.dir/requires

lib/baseClasses/CMakeFiles/baseClass.dir/clean:
	cd /home/kmccormi/sfuhome/tmp/b/lib/baseClasses && $(CMAKE_COMMAND) -P CMakeFiles/baseClass.dir/cmake_clean.cmake
.PHONY : lib/baseClasses/CMakeFiles/baseClass.dir/clean

lib/baseClasses/CMakeFiles/baseClass.dir/depend:
	cd /home/kmccormi/sfuhome/tmp/b && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kmccormi/sfuhome/tmp /home/kmccormi/sfuhome/tmp/lib/baseClasses /home/kmccormi/sfuhome/tmp/b /home/kmccormi/sfuhome/tmp/b/lib/baseClasses /home/kmccormi/sfuhome/tmp/b/lib/baseClasses/CMakeFiles/baseClass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/baseClasses/CMakeFiles/baseClass.dir/depend

