#include "Student.hpp"

Student::Student(const std::string& name, int age, const std::string& hometown, const std::string& className)
    : name(name), age(age), hometown(hometown), className(className) {}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

std::string Student::getHometown() const {
    return hometown;
}

std::string Student::getClassName() const {
    return className;
}
