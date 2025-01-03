#ifndef FULLTIMESTUDENT_H
#define FULLTIMESTUDENT_H

#include "Student.hpp"

class FullTimeStudent : public Student {
public:
    FullTimeStudent(const std::string& id, const std::string& name, const std::string& dob,
                   int year, double score);
    
    ~FullTimeStudent();
    void showInfor();
};

#endif // REGULARSTUDENT_H
