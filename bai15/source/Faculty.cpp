#include"Faculty.hpp"
#include"Exception.hpp"
#include <algorithm>
Faculty::Faculty(const std::string& name) : facultyName(name) {}

void Faculty::addStudent() {
    int studentType;
    std::cout << "Enter the type of student to add (1 - Regular, 2 - Part-Time): ";
    std::cin >> studentType;

    std::string id, name, dob, location;
    int admissionYear;
    double entryScore;

    std::cout << "Enter Student ID: ";
    std::cin >> id;

    std::cin.ignore(); // Remove leftover newline character in the input buffer

    // Validate Full Name
    while (true) {
        try {
            std::cout << "Enter Full Name: ";
            std::getline(std::cin, name);
            ExceptionHandler::validateName(name); // Validate the name
            break;
        } catch (const InvalidNameException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
        }
    }

    // Validate Date of Birth
    while (true) {
        try {
            std::cout << "Enter Date of Birth (dd/MM/YYYY): ";
            std::getline(std::cin, dob);
            ExceptionHandler::validateDOB(dob); // Validate the date of birth
            break;
        } catch (const InvalidDOBException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
        }
    }

    // Validate Admission Year
    while (true) {
        try {
            std::cout << "Enter Admission Year: ";
            std::cin >> admissionYear;
            ExceptionHandler::validateYear(admissionYear); // Validate the year
            break;
        } catch (const InvalidYearException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
        }
    }

    std::cout << "Enter Entry Score: ";
    std::cin >> entryScore;

    std::unique_ptr<Student> newStudent;

    if (studentType == 1) {
        newStudent = std::make_unique<FullTimeStudent>(id, name, dob, admissionYear, entryScore);
    } else if (studentType == 2) {
        std::cin.ignore();
        while (true) {
            try {
                std::cout << "Enter Training Location: ";
                std::getline(std::cin, location);
                ExceptionHandler::validateLocation(location); // Validate location
                break;
            } catch (const InvalidLocationException& e) {
                std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
            }
        }
        newStudent = std::make_unique<PartTimeStudent>(id, name, dob, admissionYear, entryScore, location);
    } else {
        std::cerr << "Invalid student type selected!" << std::endl;
        return;
    }

    students.push_back(std::move(newStudent));
    std::cout << "Student added successfully!" << std::endl;
}

int Faculty::getRegularStudentCount() {
    int regularCount = 0;
    for (const auto& it : students) {
        if (dynamic_cast<FullTimeStudent*>(it.get())) {
            regularCount++;
        }
    }
    return regularCount;
}

void Faculty::defineRegularStudent(std::string ID){
    int checkRegularStudent = 0;
    for (auto &it : students){
        if(it->getStudentID() == ID&& dynamic_cast<FullTimeStudent*>(it.get())!= NULL){
            checkRegularStudent = 1;
        }
    }
    if (checkRegularStudent ==1){
        std::cout<<"It is regulr student"<<std::endl;
    }
    else{
        std::cout<<"It is not regulr student"<<std::endl;
    }
}

void Faculty::showInfor(){
    if (students.empty()) {
        std::cout << "No students in faculty \"" << facultyName << "\"." << std::endl;
        return;
    }

    std::cout << "Faculty: " << facultyName << std::endl;
    std::cout << "Number of students: " << students.size() << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    for (const auto& student : students) {
        if (student) {
            student->showInfor(); // Gọi phương thức showInfo() của mỗi sinh viên
        }
    }
    std::cout << "--------------------------------------" << std::endl;
}

void Faculty::findTopEntryScore() {
    if (students.empty()) {
        std::cout << "No students in faculty \"" << facultyName << "\"." << std::endl;
        return;
    }

    Student* topStudent = nullptr;
    double highestScore = 0.0;

    for (const auto& it : students) {
        if (it->getEntryScore() > highestScore) {
            highestScore = it->getEntryScore();
            topStudent = it.get();
        }
    }

    if (topStudent) {
        std::cout << "Top Entry Score Student in Faculty \"" << facultyName << "\":" << std::endl;
        topStudent->showInfor(); 
        std::cout << "Entry Score: " << highestScore << std::endl;
    }
}

std::string Faculty::getFacultyName()const{
    return facultyName;
}


std::vector<Student*> Faculty::findPartTimeStudentsByLocationInFaculty (const std::string& location){
    std::vector<Student*> studentList;
    for (const auto& student : students) {
        if (auto* partTime = dynamic_cast<PartTimeStudent*>(student.get())) {
            if (partTime->get_Location() == location) {
                    studentList.push_back(partTime);
            }
        }
    }

    return studentList;
}

Student* Faculty::findHighestStudent() {
    Student* topStudent = nullptr; 
    double highestAverage = 0.0;   

    for (const auto& student : students) {
        
        std::vector<StudyResult> studyResults = student->getStudyResult();

        double maxAverage = 0.0;
        for (const auto& result : studyResults) {
            if (result.getSemesterAverage() > maxAverage) {
                maxAverage = result.getSemesterAverage();
            }
        }

        if (maxAverage > highestAverage) {
            highestAverage = maxAverage;
            topStudent = student.get(); 
        }
    }

    return topStudent; 
}

void Faculty::sortStudents() {
    std::sort(students.begin(), students.end(), [](const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) {
        
        bool isARegular = dynamic_cast<FullTimeStudent*>(a.get()) != nullptr;
        bool isBRegular = dynamic_cast<FullTimeStudent*>(b.get()) != nullptr;

        if (isARegular != isBRegular) {
            return isARegular; // RegularStudent xếp trước PartTimeStudent
        }

        return a->getAdmissionYear() > b->getAdmissionYear();
    });
}

std::map<int, int> Faculty::getStatisticsByYear() const{
    std::map<int, int> yearStatistics;
    for (const auto& student : students) {
        int admissionYear = student->getAdmissionYear(); // Lấy năm vào học
        yearStatistics[admissionYear]++; // Tăng số lượng sinh viên cho năm tương ứng
    }

    return yearStatistics;
}

void Faculty::displayStatisticsByYear() const {
    auto statistics = getStatisticsByYear();

    std::cout << "Statistics by year for Faculty \"" << facultyName << "\":" << std::endl;
    for (const auto& entry : statistics) {
        std::cout << "Year " << entry.first << ": " << entry.second << " students" << std::endl;
    }
}

const std::vector<std::unique_ptr<Student>>& Faculty::getStudents() const {
    return students;
}

std::vector<Student*> Faculty::findHighGPAStudentsInLastSemester(const std::vector<std::unique_ptr<Student>>& students, double minGpa) const {
    std::vector<Student*> result;

    for (const auto& student : students) {
        const auto& studyResults = student->getStudyResult();
        if (!studyResults.empty() && studyResults.back().getSemesterAverage() >= minGpa) {
            result.push_back(student.get()); // Use raw pointer
        }
    }

    return result;
}