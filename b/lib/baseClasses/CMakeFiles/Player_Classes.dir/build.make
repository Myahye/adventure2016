# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/JLUD/Desktop/Player_Classes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/JLUD/Desktop/Player_Classes/b

# Include any dependencies generated for this target.
include lib/baseClasses/CMakeFiles/Player_Classes.dir/depend.make

# Include the progress variables for this target.
include lib/baseClasses/CMakeFiles/Player_Classes.dir/progress.make

# Include the compile flags for this target's objects.
include lib/baseClasses/CMakeFiles/Player_Classes.dir/flags.make

lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o: lib/baseClasses/CMakeFiles/Player_Classes.dir/flags.make
lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o: ../lib/baseClasses/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/JLUD/Desktop/Player_Classes/b/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o"
	cd /Users/JLUD/Desktop/Player_Classes/b/lib/baseClasses && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Player_Classes.dir/Player.cpp.o -c /Users/JLUD/Desktop/Player_Classes/lib/baseClasses/Player.cpp

lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Player_Classes.dir/Player.cpp.i"
	cd /Users/JLUD/Desktop/Player_Classes/b/lib/baseClasses && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/JLUD/Desktop/Player_Classes/lib/baseClasses/Player.cpp > CMakeFiles/Player_Classes.dir/Player.cpp.i

lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Player_Classes.dir/Player.cpp.s"
	cd /Users/JLUD/Desktop/Player_Classes/b/lib/baseClasses && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/JLUD/Desktop/Player_Classes/lib/baseClasses/Player.cpp -o CMakeFiles/Player_Classes.dir/Player.cpp.s

lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o.requires:

.PHONY : lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o.requires

lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o.provides: lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o.requires
	$(MAKE) -f lib/baseClasses/CMakeFiles/Player_Classes.dir/build.make lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o.provides.build
.PHONY : lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o.provides

lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o.provides.build: lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o


# Object files for target Player_Classes
Player_Classes_OBJECTS = \
"CMakeFiles/Player_Classes.dir/Player.cpp.o"

# External object files for target Player_Classes
Player_Classes_EXTERNAL_OBJECTS =

lib/libPlayer_Classes.a: lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o
lib/libPlayer_Classes.a: lib/baseClasses/CMakeFiles/Player_Classes.dir/build.make
lib/libPlayer_Classes.a: lib/baseClasses/CMakeFiles/Player_Classes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/JLUD/Desktop/Player_Classes/b/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../libPlayer_Classes.a"
	cd /Users/JLUD/Desktop/Player_Classes/b/lib/baseClasses && $(CMAKE_COMMAND) -P CMakeFiles/Player_Classes.dir/cmake_clean_target.cmake
	cd /Users/JLUD/Desktop/Player_Classes/b/lib/baseClasses && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Player_Classes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/baseClasses/CMakeFiles/Player_Classes.dir/build: lib/libPlayer_Classes.a

.PHONY : lib/baseClasses/CMakeFiles/Player_Classes.dir/build

lib/baseClasses/CMakeFiles/Player_Classes.dir/requires: lib/baseClasses/CMakeFiles/Player_Classes.dir/Player.cpp.o.requires

.PHONY : lib/baseClasses/CMakeFiles/Player_Classes.dir/requires

lib/baseClasses/CMakeFiles/Player_Classes.dir/clean:
	cd /Users/JLUD/Desktop/Player_Classes/b/lib/baseClasses && $(CMAKE_COMMAND) -P CMakeFiles/Player_Classes.dir/cmake_clean.cmake
.PHONY : lib/baseClasses/CMakeFiles/Player_Classes.dir/clean

lib/baseClasses/CMakeFiles/Player_Classes.dir/depend:
	cd /Users/JLUD/Desktop/Player_Classes/b && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/JLUD/Desktop/Player_Classes /Users/JLUD/Desktop/Player_Classes/lib/baseClasses /Users/JLUD/Desktop/Player_Classes/b /Users/JLUD/Desktop/Player_Classes/b/lib/baseClasses /Users/JLUD/Desktop/Player_Classes/b/lib/baseClasses/CMakeFiles/Player_Classes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/baseClasses/CMakeFiles/Player_Classes.dir/depend

