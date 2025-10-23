cmake_minimum_required(VERSION 3.10)
project(chessDataLib)

add_library(chessDataLib src/chessDataLib.cpp)
target_include_directories(chessDataLib PUBLIC include)