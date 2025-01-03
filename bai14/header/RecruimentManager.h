#ifndef RECRUITMENTMANAGER_H
#define RECRUITMENTMANAGER_H

#include "Student.h"
#include "GoodStudent.h"
#include "NormalStudent.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class RecruimentManager {
private:
    std::vector<Student*> students;

public:
    ~RecruimentManager();
    void addStudent(Student* student);
    void showAllStudents() const;
    void recruitCandidates(size_t numOfRecruitments);
};

#endif // RECRUITMENTMANAGER_H
