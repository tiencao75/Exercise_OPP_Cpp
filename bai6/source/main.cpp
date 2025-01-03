#include "ManagerStudent.hpp"
#include <iostream>
#include <memory>

enum MenuOption {
    ADD_STUDENT = 1,
    DISPLAY_AGE_20,
    COUNT_AGE_23_DN,
    EXIT
};

int main() {
    ManagerStudent manager;

    int choice;
    do {
        std::cout << "\nMenu:\n"
                  << "1. Add new student\n"
                  << "2. Display students aged 20\n"
                  << "3. Count students aged 23 from DN\n"
                  << "4. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (static_cast<MenuOption>(choice)) {
            case ADD_STUDENT: {
                std::string name, hometown, className;
                int age;
                std::cin.ignore(); 
                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter age: ";
                std::cin >> age;
                std::cin.ignore(); 
                std::cout << "Enter hometown: ";
                std::getline(std::cin, hometown);
                std::cout << "Enter class: ";
                std::getline(std::cin, className);
                auto student = std::make_shared<Student>(name, age, hometown, className);
                manager.addStudent(student);
                break;
            }
            case DISPLAY_AGE_20: {
                std::cout << "Students aged 20:\n";
                manager.displayStudentsByAge(20);
                break;
            }
            case COUNT_AGE_23_DN: {
                int count = manager.countStudentsByAgeAndHometown(23, "DN");
                std::cout << "Number of students aged 23 from DN: " << count << std::endl;
                break;
            }
            case EXIT: {
                std::cout << "Exiting...\n";
                break;
            }
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != EXIT);

    return 0;
}
