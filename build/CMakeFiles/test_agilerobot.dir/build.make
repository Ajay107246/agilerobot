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
include CMakeFiles/test_agilerobot.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_agilerobot.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_agilerobot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_agilerobot.dir/flags.make

CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.obj: CMakeFiles/test_agilerobot.dir/flags.make
CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.obj: CMakeFiles/test_agilerobot.dir/includes_CXX.rsp
CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.obj: D:/agilerobot/source/agileMotorControl.cpp
CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.obj: CMakeFiles/test_agilerobot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/agilerobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.obj"
	D:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.obj -MF CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.obj.d -o CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.obj -c D:/agilerobot/source/agileMotorControl.cpp

CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.i"
	D:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/agilerobot/source/agileMotorControl.cpp > CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.i

CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.s"
	D:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/agilerobot/source/agileMotorControl.cpp -o CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.s

CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.obj: CMakeFiles/test_agilerobot.dir/flags.make
CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.obj: CMakeFiles/test_agilerobot.dir/includes_CXX.rsp
CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.obj: D:/agilerobot/test/test_agileMotorControl.cpp
CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.obj: CMakeFiles/test_agilerobot.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:/agilerobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.obj"
	D:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.obj -MF CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.obj.d -o CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.obj -c D:/agilerobot/test/test_agileMotorControl.cpp

CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.i"
	D:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/agilerobot/test/test_agileMotorControl.cpp > CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.i

CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.s"
	D:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/agilerobot/test/test_agileMotorControl.cpp -o CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.s

# Object files for target test_agilerobot
test_agilerobot_OBJECTS = \
"CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.obj" \
"CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.obj"

# External object files for target test_agilerobot
test_agilerobot_EXTERNAL_OBJECTS =

test_agilerobot.exe: CMakeFiles/test_agilerobot.dir/source/agileMotorControl.cpp.obj
test_agilerobot.exe: CMakeFiles/test_agilerobot.dir/test/test_agileMotorControl.cpp.obj
test_agilerobot.exe: CMakeFiles/test_agilerobot.dir/build.make
test_agilerobot.exe: lib/libgtest_maind.a
test_agilerobot.exe: lib/libgtestd.a
test_agilerobot.exe: CMakeFiles/test_agilerobot.dir/linkLibs.rsp
test_agilerobot.exe: CMakeFiles/test_agilerobot.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:/agilerobot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_agilerobot.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/test_agilerobot.dir/objects.a
	D:/msys64/ucrt64/bin/ar.exe qc CMakeFiles/test_agilerobot.dir/objects.a @CMakeFiles/test_agilerobot.dir/objects1.rsp
	D:/msys64/ucrt64/bin/c++.exe  -O0 -g -g  --coverage --coverage -Wl,--whole-archive CMakeFiles/test_agilerobot.dir/objects.a -Wl,--no-whole-archive -o test_agilerobot.exe -Wl,--out-implib,libtest_agilerobot.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/test_agilerobot.dir/linkLibs.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Running test_agilerobot executable...!"
	D:/agilerobot/build/test_agilerobot.exe

# Rule to build all files generated by this target.
CMakeFiles/test_agilerobot.dir/build: test_agilerobot.exe
.PHONY : CMakeFiles/test_agilerobot.dir/build

CMakeFiles/test_agilerobot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_agilerobot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_agilerobot.dir/clean

CMakeFiles/test_agilerobot.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/agilerobot D:/agilerobot D:/agilerobot/build D:/agilerobot/build D:/agilerobot/build/CMakeFiles/test_agilerobot.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_agilerobot.dir/depend

