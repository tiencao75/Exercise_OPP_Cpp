#include "GoodStudent.h"
#include "NormalStudent.h"
#include "RecruimentManager.h"
#include "Student.h"
#include "Exceptions.h"

int main() {
    RecruimentManager manager;

    std::cout << "Welcome to the Recruitment Manager!" << std::endl;
    int choice;

    do {
        std::cout << "\n========== MENU ==========" << std::endl;
        std::cout << "1. Add a student" << std::endl;
        std::cout << "2. Recruit students" << std::endl;
        std::cout << "3. Display all students" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: { // Add a student
                std::string fullName = ExceptionHandler::handleFullNameInput(Student::validateFullName);
                std::string dob = ExceptionHandler::handleDOBInput(Student::validateDoB);
                std::string phoneNumber = ExceptionHandler::handlePhoneNumberInput(Student::validatePhoneNumber);

                std::string sex, universityName, gradeLevel;
                std::cout << "Enter gender: ";
                std::getline(std::cin, sex);

                std::cout << "Enter university name: ";
                std::getline(std::cin, universityName);

                std::cout << "Enter graduation grade level: ";
                std::getline(std::cin, gradeLevel);

                int studentType;
                std::cout << "Enter student type (1: GoodStudent, 2: NormalStudent): ";
                std::cin >> studentType;
                std::cin.ignore();

                if (studentType == 1) { // GoodStudent
                    float gpa;
                    std::string bestRewardName;
                    std::cout << "Enter GPA: ";
                    std::cin >> gpa;
                    std::cin.ignore();
                    std::cout << "Enter the name of the best reward: ";
                    std::getline(std::cin, bestRewardName);

                    manager.addStudent(new GoodStudent(fullName, dob, sex, phoneNumber, universityName, gradeLevel, gpa, bestRewardName));
                } else if (studentType == 2) { // NormalStudent
                    int englishScore;
                    float entryTestScore;
                    std::cout << "Enter English score: ";
                    std::cin >> englishScore;
                    std::cin.ignore();
                    std::cout << "Enter entry test score: ";
                    std::cin >> entryTestScore;
                    std::cin.ignore();

                    manager.addStudent(new NormalStudent(fullName, dob, sex, phoneNumber, universityName, gradeLevel, englishScore, entryTestScore));
                } else {
                    std::cout << "Invalid student type! Please try again." << std::endl;
                }
                break;
            }

            case 2: { // Recruit students
                size_t numOfRecruitments;
                std::cout << "Enter the number of students to recruit (min 11, max 15): ";
                std::cin >> numOfRecruitments;
                std::cin.ignore();

                if (numOfRecruitments < 11 || numOfRecruitments > 15) {
                    std::cout << "Invalid number of recruitments! Please enter a value between 11 and 15." << std::endl;
                } else {
                    manager.recruitCandidates(numOfRecruitments);
                }
                break;
            }

            case 3: { // Display all students
                manager.showAllStudents();
                break;
            }

            case 4: { // Exit program
                std::cout << "Exiting the system. Goodbye!" << std::endl;
                break;
            }

            default: {
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 4);

    return 0;
}