/*
Implement an interface for shape, and derive circle, triangle, rectangle, square as children. Overload all three
comparison operators to compare the shapes based on their area -- if equal then their perimeter should be
considered. Only, and if only both area and perimeter are equal then the objects should be considered equal.
*/
#include <iostream>
#include <math.h>

class Shape{
    // varibles
    private:
        int perimeter = 0;
        int area = 0;
    // methods
    public:
        Shape() = default;
        Shape(const int &_area, const int &_perimeter) : area(_area),perimeter(_perimeter){}
        // virtual ~Shape() = 0;
        virtual ~Shape();
        
        // bool operator < (const Shape &r)
        bool operator < (const Shape &s){
            if( (this->area < s.area) || 
                ( (this->area == s.area)) && (this->perimeter < s.perimeter) ){
                return true;
            }
            return false;
        }
        bool operator > (const Shape &s){
            if( (this->area > s.area) || 
                ( (this->area == s.area)) && (this->perimeter > s.perimeter) ){
                return true;
            }
            return false;
        }
        bool operator == (const Shape &s){
            if( (this->area == s.area) && ( (this->area == s.area)) ){
                return true;
            }
            return false;
        }

        void print(){
             printf("Perimeter: %d, Area: %d", perimeter, area);
        }
};

Shape::~Shape(){} 


class Rectangle : public Shape {
    public:
        ~Rectangle() = default;
        Rectangle( const int &height, const int &width ) : Shape( (height*width), (2*height)+(2*width) ){}
};

class Triangle : public Shape {
    public:
        ~Triangle() = default;
        Triangle( const int &height, const int &width ): Shape( (height*width)/2, (height + width + sqrt( (std::pow(height, 2)+std::pow(width,2) )) ) ){}
};

class Circle : public Shape {
    public:
        ~Circle() = default;
        Circle( const int &radius ): Shape( 3*std::pow(radius/2,2), 3*radius ){}
};


int main(int argc, char *argv[]){

    Shape *rectangle = new Rectangle(10, 10);
    Shape *triangle = new Triangle(10,10);
    Shape *circle = new Circle(10);

    unsigned int SIZE = 3;

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
    
    delete rectangle;
    delete triangle;
    delete circle;

    return 0;
}