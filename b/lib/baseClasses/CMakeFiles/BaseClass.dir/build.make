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
CMAKE_SOURCE_DIR = /home/kmccormi/sfuhome/temp3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kmccormi/sfuhome/temp3/b

# Include any dependencies generated for this target.
include lib/baseClasses/CMakeFiles/BaseClass.dir/depend.make

# Include the progress variables for this target.
include lib/baseClasses/CMakeFiles/BaseClass.dir/progress.make

# Include the compile flags for this target's objects.
include lib/baseClasses/CMakeFiles/BaseClass.dir/flags.make

lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o: lib/baseClasses/CMakeFiles/BaseClass.dir/flags.make
lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o: ../lib/baseClasses/Npc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kmccormi/sfuhome/temp3/b/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o"
	cd /home/kmccormi/sfuhome/temp3/b/lib/baseClasses && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/BaseClass.dir/Npc.cpp.o -c /home/kmccormi/sfuhome/temp3/lib/baseClasses/Npc.cpp

lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BaseClass.dir/Npc.cpp.i"
	cd /home/kmccormi/sfuhome/temp3/b/lib/baseClasses && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kmccormi/sfuhome/temp3/lib/baseClasses/Npc.cpp > CMakeFiles/BaseClass.dir/Npc.cpp.i

lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BaseClass.dir/Npc.cpp.s"
	cd /home/kmccormi/sfuhome/temp3/b/lib/baseClasses && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kmccormi/sfuhome/temp3/lib/baseClasses/Npc.cpp -o CMakeFiles/BaseClass.dir/Npc.cpp.s

lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o.requires:
.PHONY : lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o.requires

lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o.provides: lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o.requires
	$(MAKE) -f lib/baseClasses/CMakeFiles/BaseClass.dir/build.make lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o.provides.build
.PHONY : lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o.provides

lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o.provides.build: lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o

# Object files for target BaseClass
BaseClass_OBJECTS = \
"CMakeFiles/BaseClass.dir/Npc.cpp.o"

# External object files for target BaseClass
BaseClass_EXTERNAL_OBJECTS =

lib/libBaseClass.a: lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o
lib/libBaseClass.a: lib/baseClasses/CMakeFiles/BaseClass.dir/build.make
lib/libBaseClass.a: lib/baseClasses/CMakeFiles/BaseClass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../libBaseClass.a"
	cd /home/kmccormi/sfuhome/temp3/b/lib/baseClasses && $(CMAKE_COMMAND) -P CMakeFiles/BaseClass.dir/cmake_clean_target.cmake
	cd /home/kmccormi/sfuhome/temp3/b/lib/baseClasses && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BaseClass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/baseClasses/CMakeFiles/BaseClass.dir/build: lib/libBaseClass.a
.PHONY : lib/baseClasses/CMakeFiles/BaseClass.dir/build

lib/baseClasses/CMakeFiles/BaseClass.dir/requires: lib/baseClasses/CMakeFiles/BaseClass.dir/Npc.cpp.o.requires
.PHONY : lib/baseClasses/CMakeFiles/BaseClass.dir/requires

lib/baseClasses/CMakeFiles/BaseClass.dir/clean:
	cd /home/kmccormi/sfuhome/temp3/b/lib/baseClasses && $(CMAKE_COMMAND) -P CMakeFiles/BaseClass.dir/cmake_clean.cmake
.PHONY : lib/baseClasses/CMakeFiles/BaseClass.dir/clean

lib/baseClasses/CMakeFiles/BaseClass.dir/depend:
	cd /home/kmccormi/sfuhome/temp3/b && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kmccormi/sfuhome/temp3 /home/kmccormi/sfuhome/temp3/lib/baseClasses /home/kmccormi/sfuhome/temp3/b /home/kmccormi/sfuhome/temp3/b/lib/baseClasses /home/kmccormi/sfuhome/temp3/b/lib/baseClasses/CMakeFiles/BaseClass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/baseClasses/CMakeFiles/BaseClass.dir/depend

