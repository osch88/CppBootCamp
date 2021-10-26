# Makefile for Sudoko Solver
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
assignment1: assignment1.o ../Day05/Shape/Shape.o
	$(CC) $(CFLAGS) -o assignment1 assignment1.o ../Day05/Shape/Shape.o
 
# The assignment1.o target can be written more simply
 
assignment1.o: assignment1.cpp ../Day05/Shape/Shape.hpp
	$(CC) $(CFLAGS) -c assignment1.cpp
 
Shape.o: ../Day05/Shape/Shape.hpp