#include "GoodStudent.h"

GoodStudent::GoodStudent(const std::string& fullName, const std::string& doB, const std::string& sex,
                         const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel,
                         float gpa, const std::string& bestRewardName)
    : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), gpa(gpa), bestRewardName(bestRewardName) {}

void GoodStudent::ShowMyInfor() const {
    std::cout << "Full Name: " << fullName << "\nDate of Birth: " << doB
              << "\nSex: " << sex << "\nPhone Number: " << phoneNumber
              << "\nUniversity Name: " << universityName << "\nGrade Level: " << gradeLevel
              << "\nGPA: " << gpa << "\nBest Reward: " << bestRewardName << std::endl;
}

// Getters
float GoodStudent::getGpa() const { return gpa; }
const std::string& GoodStudent::getBestRewardName() const { return bestRewardName; }

// Setters
void GoodStudent::setGpa(float gpa) { this->gpa = gpa; }
void GoodStudent::setBestRewardName(const std::string& bestRewardName) { this->bestRewardName = bestRewardName; }
