cmake_minimum_required(VERSION 3.10)
project(chessDataLib)

# Require a modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# === Library ===
add_library(chessDataLib
    src/parser.cpp
    src/PGNStatsUpdater.cpp
    src/PGNGameBuilder.cpp
    src/PGNTagParser.cpp
    src/PGNTokenizer.cpp
    src/player.cpp
    src/tournament.cpp
    src/databaseStats.cpp
    src/game.cpp
    src/utils/csv.cpp
)

target_include_directories(chessDataLib PUBLIC include)
target_compile_features(chessDataLib PUBLIC cxx_std_17)

# Enable testing if tests exist
include(CTest)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt")
    add_subdirectory(tests)
endif()
