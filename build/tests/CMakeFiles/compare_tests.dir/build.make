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

# Include any dependencies generated for this target.
include tests/CMakeFiles/compare_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/compare_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/compare_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/compare_tests.dir/flags.make

tests/CMakeFiles/compare_tests.dir/compare_tests.c.obj: tests/CMakeFiles/compare_tests.dir/flags.make
tests/CMakeFiles/compare_tests.dir/compare_tests.c.obj: D:/programcao/cpluplus/trabed2/include/cjson/tests/compare_tests.c
tests/CMakeFiles/compare_tests.dir/compare_tests.c.obj: tests/CMakeFiles/compare_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\programcao\cpluplus\trabed2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/compare_tests.dir/compare_tests.c.obj"
	cd /d D:\programcao\cpluplus\trabed2\build\tests && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/compare_tests.dir/compare_tests.c.obj -MF CMakeFiles\compare_tests.dir\compare_tests.c.obj.d -o CMakeFiles\compare_tests.dir\compare_tests.c.obj -c D:\programcao\cpluplus\trabed2\include\cjson\tests\compare_tests.c

tests/CMakeFiles/compare_tests.dir/compare_tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/compare_tests.dir/compare_tests.c.i"
	cd /d D:\programcao\cpluplus\trabed2\build\tests && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\programcao\cpluplus\trabed2\include\cjson\tests\compare_tests.c > CMakeFiles\compare_tests.dir\compare_tests.c.i

tests/CMakeFiles/compare_tests.dir/compare_tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/compare_tests.dir/compare_tests.c.s"
	cd /d D:\programcao\cpluplus\trabed2\build\tests && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\programcao\cpluplus\trabed2\include\cjson\tests\compare_tests.c -o CMakeFiles\compare_tests.dir\compare_tests.c.s

# Object files for target compare_tests
compare_tests_OBJECTS = \
"CMakeFiles/compare_tests.dir/compare_tests.c.obj"

# External object files for target compare_tests
compare_tests_EXTERNAL_OBJECTS =

tests/compare_tests.exe: tests/CMakeFiles/compare_tests.dir/compare_tests.c.obj
tests/compare_tests.exe: tests/CMakeFiles/compare_tests.dir/build.make
tests/compare_tests.exe: libcjson.dll.a
tests/compare_tests.exe: tests/libunity.a
tests/compare_tests.exe: tests/CMakeFiles/compare_tests.dir/linkLibs.rsp
tests/compare_tests.exe: tests/CMakeFiles/compare_tests.dir/objects1.rsp
tests/compare_tests.exe: tests/CMakeFiles/compare_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\programcao\cpluplus\trabed2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable compare_tests.exe"
	cd /d D:\programcao\cpluplus\trabed2\build\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\compare_tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/compare_tests.dir/build: tests/compare_tests.exe
.PHONY : tests/CMakeFiles/compare_tests.dir/build

tests/CMakeFiles/compare_tests.dir/clean:
	cd /d D:\programcao\cpluplus\trabed2\build\tests && $(CMAKE_COMMAND) -P CMakeFiles\compare_tests.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/compare_tests.dir/clean

tests/CMakeFiles/compare_tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\programcao\cpluplus\trabed2\include\cjson D:\programcao\cpluplus\trabed2\include\cjson\tests D:\programcao\cpluplus\trabed2\build D:\programcao\cpluplus\trabed2\build\tests D:\programcao\cpluplus\trabed2\build\tests\CMakeFiles\compare_tests.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/compare_tests.dir/depend
