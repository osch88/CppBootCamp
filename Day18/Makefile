# Makefile for Shape
 
CC = g++
CPPFLAGS = -Wall -g
INCLUDE = ../Day05/Shape/

# ****************************************************
 
main: main.o libShape.so
	@echo "Creating main"
	$(CC) $(CPPFLAGS) -o main main.o $(INCLUDE)/libShape.so

main.o: main.cpp libShape.so
	@echo "Creating main.o"
	$(CC) $(CPPFLAGS) -c main.cpp

libShape.so: $(INCLUDE)/Shape.cpp $(INCLUDE)/Shape.hpp
	@echo "Creating libShape.so"
	@echo -- run "export LD_LIBRARY_PATH=."
	$(CC) $(CPPFLAGS) -fPIC -shared $(INCLUDE)/Shape.cpp -o $(INCLUDE)/libShape.so
 
clean:
	@echo "Deleting..."
	rm -f *.o main *.a $(INCLUDE)/*.so