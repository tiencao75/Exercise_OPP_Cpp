#include "Fresher.hpp"
#include <iostream>

Fresher::Fresher(const std::string& id, const std::string& name, const std::string& birthDay, const std::string& phone, const std::string& email, const std::string& gradDate, const std::string& rank, const std::string& edu)
    : Employee(id, name, birthDay, phone, email, 1), graduationDate(gradDate), graduationRank(rank), education(edu) {}

Fresher::~Fresher() {}

std::string Fresher::getGraduationDate() const { return graduationDate; }
void Fresher::setGraduationDate(const std::string& date) { graduationDate = date; }

std::string Fresher::getGraduationRank() const { return graduationRank; }
void Fresher::setGraduationRank(const std::string& rank) { graduationRank = rank; }

std::string Fresher::getEducation() const { return education; }
void Fresher::setEducation(const std::string& edu) { education = edu; }

void Fresher::showInfo() const {
    std::cout << "[Fresher Employee] ID: " << getId() << ", Name: " << getFullName()
              << ", BirthDay: " << getBirthDay() << ", Phone: " << getPhone()
              << ", Email: " << getEmail() << ", GraduationDate: " << graduationDate
              << ", GraduationRank: " << graduationRank << ", Education: " << education << std::endl;
    showCertificates();
}
std::string Fresher::gettype(){
    return "Fresher";
};