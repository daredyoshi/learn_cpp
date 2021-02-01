#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name{};
    int grade{};
};


int getNumberOfStudents(){
    int numStudents {0};
    do{
        std::cout << "Enter how many students you have: \n";
        std::cin >> numStudents;
    } while (numStudents <=0);
    return numStudents;
}

std::vector<Student> getStudentGrades(){
    int numStudents = getNumberOfStudents();

    std::vector<Student> students(static_cast<std::vector<Student>::size_type>(numStudents));
    int studentIdx {1};
    for(auto& student : students){
        std::cout << "Enter name for Student #" << studentIdx << "\n";
        std::cin >> student.name;
        std::cout << "Enter grade for Student #" << studentIdx << "\n"; 
        std::cin >> student.grade;
        ++studentIdx;
    }

    return students;
}

void printStudent(Student student){
    std::cout << student.name << " got a grade of " <<  student.grade << "\n";
}

void printStudentGrades(std::vector<Student>& students){
    std::for_each(students.begin(), students.end(), printStudent);
}

bool isStudentGradeGreater(const Student& A,const Student& B){
    return A.grade > B.grade;
}

int main(){
    std::vector students = getStudentGrades();
    std::sort(students.begin(), students.end(), isStudentGradeGreater);
    printStudentGrades(students); 
    return 0;
}

