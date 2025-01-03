#ifndef MANAGER_STUDENT_HPP
#define MANAGER_STUDENT_HPP

#include "Student.hpp"
#include <vector>
#include <memory>

class ManagerStudent {
private:
    std::vector<std::shared_ptr<Student>> students;

public:
    void addStudent(const std::shared_ptr<Student>& student);
    void displayStudentsByAge(int age) const;
    int countStudentsByAgeAndHometown(int age, const std::string& hometown) const;
};

#endif // MANAGER_STUDENT_HPP
