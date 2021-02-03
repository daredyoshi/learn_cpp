#include <iostream>
#include <vector>
#include <algorithm>



struct Student {
    std::string name{};
    int grade{};
};

using student_array = std::array<Student, 8>;

student_array getStudentGrades(){
    return student_array {{
        {"Albert", 3},
        {"Ben", 5},
        {"Christine", 2},
        {"Dan", 8},
        {"Enchilada", 4},
        {"Francis", 1},
        {"Greg", 3},
        {"Hagrid", 5}
    }};
}




int main(){
    student_array students = getStudentGrades();
    const auto bestStudent = std::max_element(
            students.begin(), students.end(),
            [](Student a, Student b){
                return a.grade < b.grade; 
            });
    
    std::cout << bestStudent->name << " is the best student \n";
    return 0;
}

