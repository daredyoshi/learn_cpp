#include "Point3d.h"
#include "Vector3d.h"
#include <iostream>

void Point3d::print(){
    std::cout << "Point (" << m_x <<',' << m_y << ',' << m_z << ')';
}

bool Point3d::isEqual(Point3d P){
    return (P.m_x == m_x && P.m_y == m_y && P.m_z == m_z);
}

void Point3d::setValues(int x, int y, int z){
    m_x = x;
    m_y = y;
    m_z = z;
}

void Point3d::moveByVector(const Vector3d &v){
   m_x += v.m_x;
   m_y += v.m_y;
   m_z += v.m_z;
}
