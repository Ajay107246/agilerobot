# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/agilerobot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/agilerobot/build

# Include any dependencies generated for this target.
include _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/flags.make

_deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/flags.make
_deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/includes_CXX.rsp
_deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: _deps/googletest-src/googletest/src/gtest_main.cc
_deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/agilerobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj"
	cd D:/agilerobot/build/_deps/googletest-build/googletest && D:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj -MF CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj.d -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj -c D:/agilerobot/build/_deps/googletest-src/googletest/src/gtest_main.cc

_deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd D:/agilerobot/build/_deps/googletest-build/googletest && D:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/agilerobot/build/_deps/googletest-src/googletest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

_deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd D:/agilerobot/build/_deps/googletest-build/googletest && D:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/agilerobot/build/_deps/googletest-src/googletest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

lib/libgtest_maind.a: _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj
lib/libgtest_maind.a: _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/build.make
lib/libgtest_maind.a: _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:/agilerobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgtest_maind.a"
	cd D:/agilerobot/build/_deps/googletest-build/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd D:/agilerobot/build/_deps/googletest-build/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/build: lib/libgtest_maind.a
.PHONY : _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/build

_deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/clean:
	cd D:/agilerobot/build/_deps/googletest-build/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/clean

_deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/agilerobot D:/agilerobot/build/_deps/googletest-src/googletest D:/agilerobot/build D:/agilerobot/build/_deps/googletest-build/googletest D:/agilerobot/build/_deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/depend

