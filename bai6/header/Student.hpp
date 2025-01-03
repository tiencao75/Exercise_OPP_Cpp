#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
private:
    std::string name;
    int age;
    std::string hometown;
    std::string className;

public:
    Student(const std::string& name, int age, const std::string& hometown, const std::string& className);
    std::string getName() const;
    int getAge() const;
    std::string getHometown() const;
    std::string getClassName() const;
};

#endif // STUDENT_HPP
