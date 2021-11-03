cmake_minimum_required(VERSION 3.16.3)

project(Sudoku VERSION "0.1" DESCRIPTION "Solves all Sudokus")

# .h files
include_directories(include)

set(SOURCES src/main.cpp src/variables.cpp src/puzzle.cpp src/importer.cpp)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)

add_executable(Sudoku ${SOURCES})
