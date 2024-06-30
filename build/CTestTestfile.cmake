# CMake generated Testfile for 
# Source directory: D:/programcao/cpluplus/trabed2/include/cjson
# Build directory: D:/programcao/cpluplus/trabed2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cJSON_test "D:/programcao/cpluplus/trabed2/build/cJSON_test")
set_tests_properties(cJSON_test PROPERTIES  _BACKTRACE_TRIPLES "D:/programcao/cpluplus/trabed2/include/cjson/CMakeLists.txt;248;add_test;D:/programcao/cpluplus/trabed2/include/cjson/CMakeLists.txt;0;")
subdirs("tests")
subdirs("fuzzing")
