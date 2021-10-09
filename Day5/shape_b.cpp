#include <iostream>
#include <math.h>

class Shape{
    // varibles
    public:
        int width, height;
        int pi = 3;
        // int perimeter = 0;
        // int area = 0;
    // methods
    public:
        Shape(const int &_width, const int &_height) : width(_width),height(_height){}
        Shape(int _width){ _width = width; }
        
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

int main(){

    Rectangle rect(5,5);
    std::cout << rect.area() << "\n";

    Triangle tri(5,5);
    std::cout << tri.area() << "\n";
            

    return 0;
}