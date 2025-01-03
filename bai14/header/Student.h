#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
protected:
    std::string fullName;
    std::string doB;
    std::string sex;
    std::string phoneNumber;
    std::string universityName;
    std::string gradeLevel;



public:
    Student(const std::string& fullName, const std::string& doB, const std::string& sex,
            const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel);

    virtual ~Student() = default;

    virtual void ShowMyInfor() const = 0;

    // Getters
    const std::string& getFullName() const;
    const std::string& getDoB() const;
    const std::string& getSex() const;
    const std::string& getPhoneNumber() const;
    const std::string& getUniversityName() const;
    const std::string& getGradeLevel() const;

    // Setters
    void setFullName(const std::string& fullName);
    void setDoB(const std::string& doB);
    void setSex(const std::string& sex);
    void setPhoneNumber(const std::string& phoneNumber);
    void setUniversityName(const std::string& universityName);
    void setGradeLevel(const std::string& gradeLevel);

    // Validation methods
    static void validateFullName(const std::string& fullName);
    static void validateDoB(const std::string& doB);
    static void validatePhoneNumber(const std::string& phoneNumber);
};

#endif // STUDENT_H
