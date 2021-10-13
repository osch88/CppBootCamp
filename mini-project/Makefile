# Makefile for Sudoko Solver
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o Solver.o Printer.o
	$(CC) $(CFLAGS) -o main main.o Solver.o Printer.o
 
# The main.o target can be written more simply
 
main.o: main.cpp Solver.h Printer.h
	$(CC) $(CFLAGS) -c main.cpp
 
Solver.o: Solver.h
 
Printer.o: Printer.h