# Makefile for Sudoko Solver
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o Shape.o
	$(CC) $(CFLAGS) -o main main.o Shape.o
 
# The main.o target can be written more simply
 
main.o: main.cpp Shape.hpp
	$(CC) $(CFLAGS) -c main.cpp
 
Solver.o: Shape.hpp