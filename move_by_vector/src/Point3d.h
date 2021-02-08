#ifndef POINT_3D_H
#define POINT_3D_H

class Vector3d;

class Point3d{
private:
    double m_x {};
    double m_y {};
    double m_z {};

public:
    Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{x}, m_y{y}, m_z{z}{}

    // this is interesting because even though these variables
    // are private sinc the input variable is the same class
    // as this one we can access it. 
    bool isEqual(Point3d P);
    void setValues(int x, int y, int z);
    void print();
    void moveByVector(const Vector3d &v);
};


#endif
