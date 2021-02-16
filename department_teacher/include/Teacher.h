#ifndef TEACHER_H
#define TEACHER_H 

#include <string>

class Teacher{
private:
    std::string_view m_name;
public:
    Teacher(const std::string_view& name)
        : m_name{name} {}

    const std::string_view& getName() const { return m_name; }
};


#endif /* ifndef TEACHER_H */
