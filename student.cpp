#include <iostream>
#include <fstream>
#include <numeric> 

using namespace std;

#include "student.h"

Student::Student() {};

Student::Student(int id, string name, int midterm, int final_exam, const vector<int> & hw_grades)
    : id(id), name(name), midterm(midterm), final_exam(final_exam), hw_grades(hw_grades) {};

double Student::calculate_total_score() const {
    if (hw_grades.empty()) return 0;
    double hw_sum = 0.0;
    for (int grade : hw_grades) {
        hw_sum += grade;
    }
    double hw_average = hw_sum / hw_grades.size();
    return (midterm * 0.3) + (final_exam * 0.3) + (hw_average * 0.4);
}


Student get_a_student() {
    string name = "Johnny von Neumann";
    vector<int> hws = {89, 100, 98, 100};
    Student student(9999, name, 99, 90, hws);
    return student;
}

void print_student(Student student) {
    cout << "ID: " << student.get_id() << " Name: " << student.get_name() << endl;
    cout << "Midterm: " << student.get_midterm() << endl;
    cout << "Final: " << student.get_final_exam() << endl;
    cout << "Homeworks: ";
    for (int hw : student.get_hw_grades()) {
        cout << hw << " ";
    }
    cout << endl;
    
    cout << "Total Class Score: " << student.calculate_total_score() << endl;
}

int Student::get_id() const {
    return id;
}

string Student::get_name() const {
    return name;
}

int Student::get_midterm() const {
    return midterm;
}

int Student::get_final_exam() const {
    return final_exam;
}

vector<int> Student::get_hw_grades() const {
    return hw_grades;
}
