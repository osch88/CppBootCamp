# Makefile for Sudoko Solver
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g

OBJFILES = main.o Varibles.o Solver.o Printer.o
TARGET = bin/main
SRC = ./src
INCLUDE = ./include

# ****************************************************

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

%.o: $(SRC)/%.cpp 
	$(CC) -I$(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJFILES) $(TARGET) *~
