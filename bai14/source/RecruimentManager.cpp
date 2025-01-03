#include "RecruimentManager.h"

RecruimentManager::~RecruimentManager() {}

void RecruimentManager::addStudent(Student* student) {
    students.push_back(student);
}

void RecruimentManager::showAllStudents() const {
    for (const auto student : students) {
        student->ShowMyInfor();
        std::cout << "======================\n";
    }
}

void RecruimentManager::recruitCandidates(size_t numOfRecruitments) {
    if (numOfRecruitments < 11 || numOfRecruitments > 15) {
        std::cerr << "Number of recruits must be between 11 and 15.\n";
        return;
    }

    std::vector<GoodStudent*> goodStudentList;
    std::vector<NormalStudent*> normalStudentList;

    // Phân loại sinh viên
    for (auto& student : students) {
        if (auto goodStudent = dynamic_cast<GoodStudent*>(student)) {
            goodStudentList.push_back(goodStudent);
        } else if (auto normalStudent = dynamic_cast<NormalStudent*>(student)) {
            normalStudentList.push_back(normalStudent);
        }
    }

    // Sắp xếp GoodStudent theo GPA và tên
    std::sort(goodStudentList.begin(), goodStudentList.end(), [](GoodStudent* a, GoodStudent* b) {
        if (a->getGpa() != b->getGpa()) {
            return a->getGpa() > b->getGpa();
        }
        return a->getFullName() < b->getFullName();
    });

    // Sắp xếp NormalStudent theo Entry Test Score, English Score, và tên
    std::sort(normalStudentList.begin(), normalStudentList.end(), [](NormalStudent* a, NormalStudent* b) {
        if (a->getEntryTestScore() != b->getEntryTestScore()) {
            return a->getEntryTestScore() > b->getEntryTestScore();
        }
        if (a->getEnglishScore() != b->getEnglishScore()) {
            return a->getEnglishScore() > b->getEnglishScore();
        }
        return a->getFullName() < b->getFullName();
    });

    std::vector<Student*> recruitedCandidates;

    // Tuyển GoodStudent trước
    for (GoodStudent* goodStudent : goodStudentList) {
        if (recruitedCandidates.size() < numOfRecruitments) {
            recruitedCandidates.push_back(goodStudent);
        }
    }

    // Tuyển thêm NormalStudent nếu chưa đủ
    for (NormalStudent* normalStudent : normalStudentList) {
        if (recruitedCandidates.size() < numOfRecruitments) {
            recruitedCandidates.push_back(normalStudent);
        }
    }

    // Hiển thị danh sách ứng viên được tuyển dụng
    std::cout << "Recruited Candidates:\n";
    for (const auto& candidate : recruitedCandidates) {
        candidate->ShowMyInfor();
        std::cout << "---------------------\n";
    }

    if (recruitedCandidates.size() < numOfRecruitments) {
        std::cout << "Note:  " << recruitedCandidates.size() << " candidates were available for recruitment.\n";
    }
}
