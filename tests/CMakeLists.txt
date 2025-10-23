cmake_minimum_required(VERSION 3.10)

# Enable testing
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.0.zip
)
FetchContent_MakeAvailable(googletest)

# helper macro: add test target only if source exists
macro(maybe_add_test TARGET SRC)
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${SRC}")
    add_executable(${TARGET} ${SRC})
    target_link_libraries(${TARGET} PRIVATE gtest_main chessDataLib)
    add_test(NAME ${TARGET} COMMAND ${TARGET})
  else()
    message(STATUS "Skipping ${TARGET}: source ${SRC} not found")
  endif()
endmacro()

# Add tests only if the corresponding source files are present
maybe_add_test(test_csv test_csv.cpp)
maybe_add_test(test_stats test_database_stats.cpp)
maybe_add_test(test_pgn test_pgn_builder.cpp)
maybe_add_test(test_tournament test_tournament.cpp)
maybe_add_test(test_parser test_parser_integration.cpp)

# legacy single-file test (keeps previous test_core if present)
maybe_add_test(test_core test_core.cpp)