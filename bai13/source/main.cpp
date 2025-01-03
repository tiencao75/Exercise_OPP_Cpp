#include <iostream>
#include <memory>
#include "ManagerEmployee.hpp"
#include "Experience.hpp"
#include "Fresher.hpp"
#include "Intern.hpp"
#include "Exceptions.hpp"

template <typename Func>
std::string inputWithValidation(const std::string& prompt, Func validator) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (validator(input)) { // Call validation function and check the result
            return input;
        }
        std::cout << "Invalid input. Please try again.\n";
    }
}

int main() {
    ManagerEmployee manager;
    int choice;
    do {
        std::cout << "1. Add Employee\n2. Edit Employee\n3. Delete Employee\n";
        std::cout << "4. Find Interns\n5. Find Experience\n6. Find Freshers\n7. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        switch (choice) {
        case 1: { // Add Employee
            try {
                std::string id = inputWithValidation("Enter ID: ", [](const std::string&) { return true; }); // No validation
                std::string name = inputWithValidation("Enter name: ", ExceptionHandler::validateFullName);
                std::string dob = inputWithValidation("Enter birthday (dd/MM/yyyy): ", ExceptionHandler::validateDate);
                std::string email = inputWithValidation("Enter email: ", ExceptionHandler::validateEmail);
                std::string phone = inputWithValidation("Enter phone: ", ExceptionHandler::validatePhone);

                std::cout << "Enter type (Intern/Experience/Fresher): ";
                std::string type;
                std::getline(std::cin, type);

                std::shared_ptr<Employee> employee;
                if (type == "Intern") {
                    std::string majors = inputWithValidation("Enter majors: ", [](const std::string&) { return true; });
                    std::string semester = inputWithValidation("Enter semester: ", [](const std::string&) { return true; });
                    std::string universityName = inputWithValidation("Enter university name: ", [](const std::string&) { return true; });

                    employee = std::make_shared<Intern>(id, name, dob, phone, email, majors, semester, universityName);
                } else if (type == "Experience") {
                    int expInYear;
                    std::cout << "Enter years of experience: ";
                    std::cin >> expInYear;
                    std::cin.ignore();

                    std::string proSkill = inputWithValidation("Enter professional skill: ", [](const std::string&) { return true; });
                    employee = std::make_shared<Experience>(id, name, dob, phone, email, expInYear, proSkill);
                } else if (type == "Fresher") {
                    std::string gradDate = inputWithValidation("Enter graduation date (dd/MM/yyyy): ", ExceptionHandler::validateDate);
                    std::string rank = inputWithValidation("Enter graduation rank: ", [](const std::string&) { return true; });
                    std::string edu = inputWithValidation("Enter education: ", [](const std::string&) { return true; });

                    employee = std::make_shared<Fresher>(id, name, dob, phone, email, gradDate, rank, edu);
                } else {
                    std::cout << "Invalid type!\n";
                    break;
                }

                manager.addEmployee(employee);
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
            break;
        }

        case 2:
            manager.updateEmployeeById(inputWithValidation("Enter Employee ID to edit: ", [](const std::string&) { return true; }));
            break;

        case 3:
            manager.removeEmployeeById(inputWithValidation("Enter Employee ID to delete: ", [](const std::string&) { return true; }));
            break;

        case 4:
            manager.showAllIntern();
            break;

        case 5:
            manager.showAllExperience();
            break;

        case 6:
            manager.showAllFresher();
            break;

        case 7:
            std::cout << "Exited\n";
            break;

        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}

