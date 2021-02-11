#include "Department.h"

std::ostream& operator<<(std::ostream &out, const Department &department){
    for(Teacher &teacher : department.m_teachers){
        std::cout << teacher.getName();
    }
    return out;
}
