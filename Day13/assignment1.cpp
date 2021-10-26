/*
Write a function template which receives two of any shapes from last week’s assignment, compares them, and
prints out the result.
*/
#include "../Day05/Shape/Shape.hpp"
#include <iostream>

template<typename T1>
void compare(T1 val1, T1 val2){
    if( val1 == val2 ) std::cout << "Equal" << std::endl;
    else if ( val1 > val2 ) std::cout << val1 << " is bigger." << std::endl;
    else if ( val1 < val2 ) std::cout << val1 << " is smaller." << std::endl;
}

// void print(Shape *point){
//     std::string name = point->myType();
//     std::cout << name << std::endl;
// }

int main(int argc, char *argv[]){

    // Shape *c1 = new Circle(10, "Circle");
    // Shape *c2 = new Rectangle(5,5,"Rectangle");
   
    Circle c1 = Circle(1, "First circle");
    Circle c2 = Circle(2, "Second circle");

    std::cout << "\nCompare shapes: ";
    compare(c1, c2);

    std::cout << "\nCompare integers: ";
    compare(5,8);

    // delete c1;
    // delete c2;

    return 0;
}
