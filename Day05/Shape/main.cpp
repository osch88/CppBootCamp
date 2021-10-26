/*
Implement an interface for shape, and derive circle, triangle, rectangle, square as children. Overload all three
comparison operators to compare the shapes based on their area -- if equal then their perimeter should be
considered. Only, and if only both area and perimeter are equal then the objects should be considered equal.
*/
#include "Shape.hpp"

int main(int argc, char *argv[]){

    Shape *rectangle = new Rectangle(10, 10, "rectangle");
    Shape *triangle = new Triangle(10,10, "triangle");
    Shape *circle = new Circle(10, "circle");

    int SIZE = 3;

    Shape *shapes[SIZE] = {
        rectangle,
        triangle,
        circle
    };
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if( *shapes[i] > *shapes[j] ) printf("%d\tis larger than: \t%d\n", i, j);
            if( *shapes[i] < *shapes[j] ) printf("%d\tis smaller than: \t%d\n", i, j);
            if( *shapes[i] == *shapes[j] ) printf("%d\tis equal to:    \t%d\n", i, j);
        }
    }
    
    std::cout << *shapes[1] << std::endl;

    delete rectangle;
    delete triangle;
    delete circle;

    return 0;
}
