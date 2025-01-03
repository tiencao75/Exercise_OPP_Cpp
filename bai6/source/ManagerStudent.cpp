#include "ManagerStudent.hpp"
#include <iostream>

void ManagerStudent::addStudent(const std::shared_ptr<Student>& student) {
    students.push_back(student);
}

void ManagerStudent::displayStudentsByAge(int age) const {
    for (const auto& student : students) {
        if (student->getAge() == age) {
            std::cout << "Name: " << student->getName()
                      << ", Age: " << student->getAge()
                      << ", Hometown: " << student->getHometown()
                      << ", Class: " << student->getClassName()
                      << std::endl;
        }
    }
}

int ManagerStudent::countStudentsByAgeAndHometown(int age, const std::string& hometown) const {
    int count = 0;
    for (const auto& student : students) {
        if (student->getAge() == age && student->getHometown() == hometown) {
            ++count;
        }
    }
    return count;
}
