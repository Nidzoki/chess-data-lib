# CMake generated Testfile for 
# Source directory: /workspaces/chess-data-lib/tests
# Build directory: /workspaces/chess-data-lib/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_csv "/workspaces/chess-data-lib/build/tests/test_csv")
set_tests_properties(test_csv PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/chess-data-lib/tests/CMakeLists.txt;18;add_test;/workspaces/chess-data-lib/tests/CMakeLists.txt;25;maybe_add_test;/workspaces/chess-data-lib/tests/CMakeLists.txt;0;")
add_test(test_core "/workspaces/chess-data-lib/build/tests/test_core")
set_tests_properties(test_core PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/chess-data-lib/tests/CMakeLists.txt;18;add_test;/workspaces/chess-data-lib/tests/CMakeLists.txt;32;maybe_add_test;/workspaces/chess-data-lib/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
