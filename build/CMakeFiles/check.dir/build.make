# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\programcao\VS\visual\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\programcao\VS\visual\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\programcao\cpluplus\trabed2\include\cjson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\programcao\cpluplus\trabed2\build

# Utility rule file for check.

# Include any custom commands dependencies for this target.
include CMakeFiles/check.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/check.dir/progress.make

CMakeFiles/check: cJSON_test.exe
	D:\programcao\VS\visual\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\ctest.exe --output-on-failure

check: CMakeFiles/check
check: CMakeFiles/check.dir/build.make
.PHONY : check

# Rule to build all files generated by this target.
CMakeFiles/check.dir/build: check
.PHONY : CMakeFiles/check.dir/build

CMakeFiles/check.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\check.dir\cmake_clean.cmake
.PHONY : CMakeFiles/check.dir/clean

CMakeFiles/check.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\programcao\cpluplus\trabed2\include\cjson D:\programcao\cpluplus\trabed2\include\cjson D:\programcao\cpluplus\trabed2\build D:\programcao\cpluplus\trabed2\build D:\programcao\cpluplus\trabed2\build\CMakeFiles\check.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/check.dir/depend

