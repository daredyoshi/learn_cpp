#include "Department.h"

std::ostream& operator<<(std::ostream &out, const Department &department){
    out << "Department: ";
    for(const auto &teacher : department.m_teachers){
        std::cout << teacher.get().getName() << ' ';
    }
    out << '\n';
    
    return out;
}
