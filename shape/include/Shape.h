#ifndef SHAPE_H
#define SHAPE_H value
#pragma once

#include <iostream>


class Shape{
public:
    friend std::ostream& operator<<(std::ostream& out, const Shape &s);
    virtual std::ostream& print(std::ostream& out) const = 0;

    virtual ~Shape() = default; 
};

#endif /* ifndef SHAPE_H */



