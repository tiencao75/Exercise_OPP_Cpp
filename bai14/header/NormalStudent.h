#ifndef NORMALSTUDENT_H
#define NORMALSTUDENT_H

#include "Student.h"

class NormalStudent : public Student {
private:
    int englishScore;
    float entryTestScore;

public:
    NormalStudent(const std::string& fullName, const std::string& doB, const std::string& sex,
                  const std::string& phoneNumber, const std::string& universityName, const std::string& gradeLevel,
                  int englishScore, float entryTestScore);

    void ShowMyInfor() const override;

    // Getters
    int getEnglishScore() const;
    float getEntryTestScore() const;

    // Setters
    void setEnglishScore(int englishScore);
    void setEntryTestScore(float entryTestScore);
};

#endif // NORMALSTUDENT_H
