#include "Circle.h"

std::ostream& Circle::print(std::ostream& out) const{
    return out << "Circle(" << m_center << ", radius " << m_radius << ")\n";
}
