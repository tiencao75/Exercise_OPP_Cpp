#include "NormalStudent.h"

NormalStudent::NormalStudent(const std::string& fullName, const std::string& doB, const std::string& sex,
                             const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel,
                             int englishScore, float entryTestScore)
    : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), englishScore(englishScore), entryTestScore(entryTestScore) {}

void NormalStudent::ShowMyInfor() const {
    std::cout << "Full Name: " << fullName << "\nDate of Birth: " << doB
              << "\nSex: " << sex << "\nPhone Number: " << phoneNumber
              << "\nUniversity Name: " << universityName << "\nGrade Level: " << gradeLevel
              << "\nEnglish Score: " << englishScore << "\nEntry Test Score: " << entryTestScore << std::endl;
}

// Getters
int NormalStudent::getEnglishScore() const { return englishScore; }
float NormalStudent::getEntryTestScore() const { return entryTestScore; }

// Setters
void NormalStudent::setEnglishScore(int englishScore) { this->englishScore = englishScore; }
void NormalStudent::setEntryTestScore(float entryTestScore) { this->entryTestScore = entryTestScore; }
