#include "Experience.hpp"
#include <iostream>

Experience::Experience(const std::string& id, const std::string& name, const std::string& birthDay,
 const std::string& phone, const std::string& email, int exp, const std::string& skill)
    : Employee(id, name, birthDay, phone, email, 0), expInYear(exp), proSkill(skill) {}

Experience::~Experience() {}

int Experience::getExpInYear() const { return expInYear; }
void Experience::setExpInYear(int exp) { expInYear = exp; }

std::string Experience::getProSkill() const { return proSkill; }
void Experience::setProSkill(const std::string& skill) { proSkill = skill; }

void Experience::showInfo() const {
    std::cout << "[Experience Employee] ID: " << getId() << ", Name: " << getFullName()
              << ", BirthDay: " << getBirthDay() << ", Phone: " << getPhone()
              << ", Email: " << getEmail() << ", ExpInYear: " << expInYear
              << ", ProSkill: " << proSkill << std::endl;
    showCertificates();
}

std::string Experience::gettype(){
    return "Experience";
};