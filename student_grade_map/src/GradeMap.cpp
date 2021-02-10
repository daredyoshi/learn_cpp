#include "GradeMap.h"
#include <algorithm>

char& GradeMap::operator[] (const std::string &name){
    auto index { std::find_if(std::begin(m_map), std::end(m_map), [&](
                const auto& student){ 
                    return student.name == name;
                })};
    if (index != std::end(m_map)){
        return index->grade;
    }
    else{
        m_map.push_back({name});
        return m_map.back().grade;
    }


}
