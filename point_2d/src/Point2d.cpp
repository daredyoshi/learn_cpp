#include <iostream>
#include <cmath>
#include "Point2d.h"

void Point2d::print() const {
    std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
}

double Point2d::distanceTo(Point2d p) const{
    double x_dist {p.getX() - m_x};
    double y_dist {p.getY() - m_y};
    return std::sqrt((x_dist *x_dist ) + (y_dist * y_dist)); 
}
