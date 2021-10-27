# Makefile for Shape
 
CC = g++
CPPFLAGS = -Wall -g
 
# ****************************************************

libShape.so: Shape.cpp Shape.hpp
	@echo "Creating libShape.so"
	$(CC) $(CPPFLAGS) -fPIC -shared -c Shape.cpp -o libShape.so

clean:
	@echo "Deleting..."
	rm -f *.so