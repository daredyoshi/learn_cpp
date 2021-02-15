#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Teacher.h"
#include <functional>
#include <ostream>
#include <vector>
#include <iostream>

class Department{
private:
    std::vector<std::reference_wrapper<Teacher>> m_teachers {}; 


public:
    Department() {}

    void add(Teacher &teacher){
        m_teachers.push_back(teacher);
    }

    friend std::ostream& operator<<(std::ostream &out, const Department &department);
};


#endif /* ifndef DEPARTMENT_H

#include "Teacher.h"

class Department{
private:
    const Teacher& m_teacher
}
 */
