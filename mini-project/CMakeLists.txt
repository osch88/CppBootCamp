cmake_minimum_required(VERSION 3.16.3)

project(Sudoku)

# .h files
include_directories(include)

set(SOURCES src/main.cpp src/Varibles.cpp src/Solver.cpp src/Printer.cpp)

add_executable(Sudoku ${SOURCES})
