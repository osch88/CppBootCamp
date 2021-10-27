#include "Shape.hpp"

void Shape::print()
{
    printf("Perimeter: %d, Area: %d\n", perimeter, area);
}
bool Shape::operator>(const Shape &s)
{
    if ( (this->area > s.area) ||
        ( (this->area == s.area) && (this->perimeter > s.perimeter) ) )
    {
        return true;
    }
    return false;
}
bool Shape::operator==(const Shape &s)
{
    if ((this->area == s.area) && ((this->area == s.area)))
    {
        return true;
    }
    return false;
}

bool Shape::operator<(const Shape &s)
{
    if ( (this->area < s.area) ||
        ( (this->area == s.area) && (this->perimeter < s.perimeter) ) )
    {
        return true;
    }
    return false;
}

std::ostream & operator << (std::ostream &out, const Shape &c){
    out << c.whoami;
    return out;
}
// Shape::operator std::string () const{
//     return whoami;
// }

Shape::~Shape() {}