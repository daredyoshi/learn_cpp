#ifndef CIRCLE_H
#define CIRCLE_H
#pragma once

#include "Shape.h"
#include "Point.h"

class Circle: public Shape{
private:
    Point m_center;
    int m_radius;

public:
    Circle(Point p, int radius)
        : m_center{p}, m_radius{radius} {}

    virtual std::ostream& print(std::ostream& out) const override;
    int getRadius() const{ return m_radius; }
};

#endif 
