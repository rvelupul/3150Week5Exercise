#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <numeric> 

struct Student {
public:
    Student();
    Student(int id, std::string name, int midterm, int final_exam, const std::vector<int>& hw_grades);

    int get_id() const;
    std::string get_name() const;
    int get_midterm() const;
    int get_final_exam() const;
    std::vector<int> get_hw_grades() const;
    double calculate_total_score() const;

private:
    int id;
    std::string name;
    int midterm;
    int final_exam;
    std::vector<int> hw_grades;
};

void print_student(Student student);

#endif 
