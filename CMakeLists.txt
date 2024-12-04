cmake_minimum_required(VERSION 3.24)
project(WarcraftKeyCountVisualiser)

set(CMAKE_CXX_STANDARD 20)

add_executable(WarcraftKeyCountVisualiser src/main.cpp src/CsvReader.cpp src/CsvReader.h src/KeyData/Key.h src/KeyData/Player.h src/KeyData/Key.cpp src/KeyData/Player.cpp)
