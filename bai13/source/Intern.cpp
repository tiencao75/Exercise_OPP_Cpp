#include "Intern.hpp"
#include <iostream>

Intern::Intern(const std::string& id, const std::string& name, const std::string& birthDay, const std::string& phone, const std::string& email, const std::string& majors, const std::string& semester, const std::string& uniName)
    : Employee(id, name, birthDay, phone, email, 2), majors(majors), semester(semester), universityName(uniName) {}

Intern::~Intern() {}

std::string Intern::getMajors() const { return majors; }
void Intern::setMajors(const std::string& majors) { this->majors = majors; }

std::string Intern::getSemester() const { return semester; }
void Intern::setSemester(const std::string& semester) { this->semester = semester; }

std::string Intern::getUniversityName() const { return universityName; }
void Intern::setUniversityName(const std::string& uniName) { this->universityName = uniName; }

void Intern::showInfo() const {
    std::cout << "[Intern Employee] ID: " << getId() << ", Name: " << getFullName()
              << ", BirthDay: " << getBirthDay() << ", Phone: " << getPhone()
              << ", Email: " << getEmail() << ", Majors: " << majors
              << ", Semester: " << semester << ", University: " << universityName << std::endl;
    showCertificates();
}
std::string Intern::gettype(){
    return "Intern";
};
