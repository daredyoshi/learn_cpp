#include <string>
#include <iostream>
#include <vector>

#include "Circle.h"
#include "Triangle.h"

int getLargestRadius(std::vector<Shape*> v){
    int largest {0};

    for(const auto* shape : v){
        // // Ensure the dynamic cast succeeds by checking for a null pointer result
        if (auto *c{ dynamic_cast<const Circle*>(shape) }){
            // now we know we have only circles.
            if(c->getRadius() > largest){
                largest = c->getRadius();
            }
        }
    }
    return largest;
}

int main()
{
   	std::vector<Shape*> v{
      new Circle{Point{1, 2, 3}, 7},
      new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
      new Circle{Point{4, 5, 6}, 3}
    };

    for (const auto* shape: v){
        std::cout << *shape << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; 

    for (const auto* shape: v){
        delete shape;
    }
}

