#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Teacher.h"
#include <functional>
#include <ostream>
#include <vector>
#include <iostream>

class Department{
private:
    // For this one, I don't think you can have dynamic lists of references?
    // Because references have to be initialized and cannot be reassigned.
    std::vector<std::reference_wrapper<Teacher>> m_teachers {}; 


public:
    Department() {}

    void add(Teacher &teacher){
        m_teachers.push_back(teacher);
    }

    friend std::ostream& operator<<(std::ostream &out, const Department &department);
};


#endif 
