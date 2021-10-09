#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <math.h>

class Shape{
    // varibles
    private:
        int area = 0;
        int perimeter = 0;

    // methods
    public:
        Shape() = default;
        Shape(const int &_p, const int &_a)
        void print(int &_area, int &_perimeter){
             std::cout << _area << " " << _perimeter << std::endl; 
             }
        // bool operator < (const Shape &r)
};

class Rectangle : public Shape {
    public:
        Rectangle( int _width, int _height ) : Shape(_width, _height){}
        
        int area(){ return height * width; };
        int perimeter(){ return height*2 + width*2; }
};

class Triangle : Shape {
    public:
        Triangle( int _width, int _height ): Shape(_width, _height){}
        int area(){ return height * width / 2; }
        int perimeter(){ return height + width + sqrt( pow(height,2) + pow(width,2) ); }
};

class Circle : Shape {
    public:
        Circle( int &_width ): Shape(_width){}
        int area(){ return ( pi*pow(width/2,2) ); }
        int perimeter(){ return pi*width; }
};

#endif