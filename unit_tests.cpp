#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

#include <vector>

using namespace std;

TEST_CASE("Testing calculate_total_score functionality") {

    vector<int> perfect_hw_grades = {100, 100, 100};
    Student student3(3, "Test Student 3", 100, 100, perfect_hw_grades);
    CHECK_EQ(student3.calculate_total_score(), 100);

    Student student4(4, "Test Student 4", 0, 0, {});
    REQUIRE(student4.calculate_total_score() == 0);

    vector<int> low_hw_grades = {60, 55, 65};
    Student student5(5, "Test Student 5", 60, 60, low_hw_grades);
    CHECK_FALSE(student5.calculate_total_score() == 100);
}

TEST_CASE("Student with all zero grades") {
    Student studentZero(6, "Zero Student", 0, 0, {0, 0, 0});
    CHECK_EQ(studentZero.calculate_total_score(), 0);
}

TEST_CASE("Student with high homework and perfect exams") {
    std::vector<int> highHomeworkGrades = {98, 97, 99}; 
    Student studentPerfectExams(9, "Perfect Exams Student", 100, 100, highHomeworkGrades);
    CHECK_EQ(studentPerfectExams.calculate_total_score(), doctest::Approx(99.2)); 
}



