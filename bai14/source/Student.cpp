#include "Student.h"
#include "Exceptions.h"
#include <regex>

// Getters
const std::string& Student::getFullName() const { return fullName; }
const std::string& Student::getDoB() const { return doB; }
const std::string& Student::getSex() const { return sex; }
const std::string& Student::getPhoneNumber() const { return phoneNumber; }
const std::string& Student::getUniversityName() const { return universityName; }
const std::string& Student::getGradeLevel() const { return gradeLevel; }

// Setters
void Student::setFullName(const std::string& fullName) { this->fullName = fullName; }
void Student::setDoB(const std::string& doB) { this->doB = doB; }
void Student::setSex(const std::string& sex) { this->sex = sex; }
void Student::setPhoneNumber(const std::string& phoneNumber) { this->phoneNumber = phoneNumber; }
void Student::setUniversityName(const std::string& universityName) { this->universityName = universityName; }
void Student::setGradeLevel(const std::string& gradeLevel) { this->gradeLevel = gradeLevel; }

Student::Student(const std::string& fullName, const std::string& doB, const std::string& sex,
                 const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel)
    : fullName(fullName), doB(doB), sex(sex), phoneNumber(phoneNumber), universityName(universityName), gradeLevel(gradeLevel) {
    validateFullName(fullName);
    validateDoB(doB);
    validatePhoneNumber(phoneNumber);
}

void Student::validateFullName(const std::string& fullName) {
    if (fullName.length() < 10 || fullName.length() > 50) {
        throw InvalidFullNameException("Full name must be between 10 and 50 characters.");
    }
}

void Student::validateDoB(const std::string& doB) {
    std::regex dateRegex(R"(^\d{2}/\d{2}/\d{4}$)");
    if (!std::regex_match(doB, dateRegex)) {
        throw InvalidDOBException("Date of birth must be in the format dd/MM/YYYY.");
    }
}

void Student::validatePhoneNumber(const std::string& phoneNumber) {
    std::regex phoneRegex(R"(^((090|098|091|031|035|038)\d{7})$)");
    if (!std::regex_match(phoneNumber, phoneRegex)) {
        throw InvalidPhoneNumberException("Phone number must start with 090, 098, 091, 031, 035, or 038 and be 10 digits long.");
    }
}