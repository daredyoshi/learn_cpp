#pragma once
#ifndef GRADE_MAP_H
#define GRADE_MAP_H

#include<string>
#include<vector>

struct StudentGrade{
    std::string name {};
    char grade {'F'};
};

class GradeMap{
private:
    std::vector<StudentGrade> m_map{};

public:
    char& operator[] (const std::string& index);
};


#endif /* ifndef GRADE_MAP_H
 */


