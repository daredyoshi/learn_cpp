#include "Triangle.h"

std::ostream& Triangle::print(std::ostream& out) const{
    return out << "Triangle(" << m_a << ", " << m_b << ", " << m_c << ")\n";
}
