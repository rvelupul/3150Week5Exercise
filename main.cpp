#include "student.h"
#include <iostream>

int main() {
    std::vector<int> hw_grades = {90, 95, 100};
    Student student(1, "John", 85, 90, hw_grades);
    print_student(student);
    return 0;
}
