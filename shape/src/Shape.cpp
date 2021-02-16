#include "Shape.h"

std::ostream& operator<<(std::ostream& out, const Shape &s){
    return s.print(out);
}

std::ostream& Shape::print(std::ostream& out) const{ 
    return out << "Shape";
}
