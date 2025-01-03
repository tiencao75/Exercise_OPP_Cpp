#include <iostream>
#include "School.hpp"
#include "Exception.hpp"
#include <limits>

void displayMenu() {
    std::cout << "========== MENU ==========" << std::endl;
    std::cout << "1. Add a new faculty" << std::endl;
    std::cout << "2. Display all faculties" << std::endl;
    std::cout << "3. Add a student to a faculty" << std::endl;
    std::cout << "4. Get total number of regular students" << std::endl;
    std::cout << "5. Find the student with the highest entry score in each faculty" << std::endl;
    std::cout << "6. Add study results for a student" << std::endl;
    std::cout << "7. Get a list of part-time students by location" << std::endl;
    std::cout << "8. Get students with a GPA of 8.0 or higher in the last semester" << std::endl;
    std::cout << "9. Find the student with the highest average GPA in each faculty" << std::endl;
    std::cout << "10. Sort students in each faculty" << std::endl;
    std::cout << "11. Display statistics of students by admission year" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Choose an option: ";
}

int main() {
    School school("FPT University");
    int option;

    do {
        displayMenu();
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
            case 1: { // Add a new faculty
                std::string facultyName = ExceptionHandler::handleStringInput(
                 ExceptionHandler::validateName, "Enter the name of the faculty: ");
                school.addFaculty(facultyName);
                break;
            }
            case 2: { // Display all faculties
                school.showAllFaculties();
                break;
            }
            case 3: { // Add a student to a faculty
                std::string facultyName = ExceptionHandler::handleStringInput(
                    ExceptionHandler::validateName, "Enter the faculty name: ");
                for (auto& faculty : school.getFaculties()) {
                    if (faculty.getFacultyName() == facultyName) {
                        faculty.addStudent();
                        break;
                    }
                }
                break;
            }
            case 4: { // Get total number of regular students
                std::cout << "Total number of regular students: " << school.getTotalRegularStudents() << std::endl;
                break;
            }
            case 5: { // Find the student with the highest entry score in each faculty
                school.findHighestEntryScoreStudent();
                break;
            }
            case 6: { // Add study results for a student
                std::string studentID = ExceptionHandler::handleStringInput(
                    ExceptionHandler::validateID, "Enter the student ID: ");
                std::string semesterName = ExceptionHandler::handleStringInput(
                    ExceptionHandler::validateName, "Enter the semester name: ");
                double semesterAverage = ExceptionHandler::handleIntegerInput(
                    [](int avg) { if (avg < 0 || avg > 10) throw std::invalid_argument("Invalid semester average."); },
                    "Enter the semester average (0-10): ");

                bool studentFound = false;
                for (auto& faculty : school.getFaculties()) {
                    for (auto& student : faculty.getStudents()) {
                        if (student->getStudentID() == studentID) {
                            student->addStudyResult(semesterName, semesterAverage);
                            studentFound = true;
                            std::cout << "Study result added successfully!" << std::endl;
                            break;
                        }
                    }
                    if (studentFound) break;
                }
                if (!studentFound) {
                    std::cerr << "Student not found. Please try again.\n";
                }
                break;
            }
            case 7: { // Get a list of part-time students by location
                school.findPartTimeStudentsByLocation();
                break;
            }
            case 8: { // Get students with GPA >= 8.0 in the last semester
                double minGPA = 8.0;
                for (auto& faculty : school.getFaculties()) {
                    auto students = faculty.findHighGPAStudentsInLastSemester(faculty.getStudents(), minGPA);
                    for (const auto& student : students) {
                        student->showInfor();
                    }
                }
                break;
            }
            case 9: { // Find the student with the highest average GPA in each faculty
                school.findHighestGPAStudent();
                break;
            }
            case 10: { // Sort students in each faculty
                school.sort();
                break;
            }
            case 11: { // Display statistics of students by admission year
                school.displayStatisticsForAllFaculties();
                break;
            }
            case 0: // Exit
                std::cout << "Exiting the program!" << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again!" << std::endl;
        }
    } while (option != 0);

    return 0;
}
