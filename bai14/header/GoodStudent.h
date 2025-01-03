#ifndef GOODSTUDENT_H
#define GOODSTUDENT_H

#include "Student.h"

class GoodStudent : public Student {
private:
    float gpa;
    std::string bestRewardName;

public:
    GoodStudent(const std::string& fullName, const std::string& doB, const std::string& sex,
                const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel,
                float gpa, const std::string& bestRewardName);

    void ShowMyInfor() const override;

    // Getters
    float getGpa() const;
    const std::string& getBestRewardName() const;

    // Setters
    void setGpa(float gpa);
    void setBestRewardName(const std::string& bestRewardName);
};

#endif // GOODSTUDENT_H
