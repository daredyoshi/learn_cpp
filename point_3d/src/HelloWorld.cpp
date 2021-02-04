#include <iostream>

class Point3d{
    int m_x {};
    int m_y {};
    int m_z {};

public:
    // this is interesting because even though these variables
    // are private sinc the input variable is the same class
    // as this one we can access it. 
    bool isEqual(Point3d P){
        return (P.m_x == m_x && P.m_y == m_y && P.m_z == m_z);
    }
    void setValues(int x, int y, int z){
        m_x = x;
        m_y = y;
        m_z = z;
    };
    void print(){
        std::cout << '<' << m_x <<',' << m_y << ',' << m_z << '>';
    }
};


int main()
{
    Point3d point1;
    point1.setValues(1, 2, 3);
 
    Point3d point2;
    point2.setValues(1, 2, 3);
 
    if (point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }
 
    Point3d point3;
    point3.setValues(3, 4, 5);
 
    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }
 
}

