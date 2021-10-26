#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include <string>
#include <math.h>

class Shape{
    // varibles
    private:
        int area;
        int perimeter;
        std::string whoami;
    // methods
    public:
        Shape() = default;
        Shape(const int &_area, const int &_perimeter, const std::string &_whoami = "nothing") : area(_area),perimeter(_perimeter), whoami(_whoami){}
        virtual ~Shape() = 0;
        // virtual ~Shape();
        // bool operator < (const Shape &r)
        bool operator < (const Shape &s);
        bool operator > (const Shape &s);
        bool operator == (const Shape &s);
        void print();
        // print out whoami
        friend std::ostream & operator << (std::ostream &out, const Shape &c);
};

class Rectangle : public Shape {
    public:
        ~Rectangle() = default;
        Rectangle( const int &height, const int &width, const std::string &whoami ) : Shape( (height*width), (2*height)+(2*width), whoami ){}
};

class Triangle : public Shape {
    public:
        ~Triangle() = default;
        Triangle( const int &height, const int &width, const std::string &whoami ): Shape( (height*width)/2, (height + width + sqrt( (std::pow(height, 2)+std::pow(width,2) )) ), whoami ){}
};

class Circle : public Shape {
    public:
        ~Circle() = default;
        Circle( const int &radius, const std::string &whoami ): Shape( 3*std::pow(radius/2,2), 3*radius, whoami ){}
};

#endif