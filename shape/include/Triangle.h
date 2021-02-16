#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Shape.h"

class Triangle : public Shape {
private:
    Point m_a;
    Point m_b;
    Point m_c;

public:
    Triangle(Point a, Point b, Point c)
        : m_a{a}, m_b{b}, m_c{c} {}

    virtual std::ostream& print(std::ostream& out) const override;
};

#endif /* ifndef TRIANGLE_H
 */
