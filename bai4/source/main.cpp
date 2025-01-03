#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Person.hpp"
#include "Family.hpp"
#include "Town.hpp"

enum FamilyMenuOption {
    AddFamily = 1,
    ViewAllFamilies,
    ExitMenu
};

int main() {
    Town town;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a family\n";
        std::cout << "2. View all families in the town\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case AddFamily: {
            std::cin.ignore();
            std::string address;
            std::cout << "Enter address: ";
            std::getline(std::cin, address);

            int number;
            std::cout << "Enter number of persons in the family: ";
            std::cin >> number;
            std::cin.ignore();

            std::vector<std::shared_ptr<Person>> persons;

            for (int j = 0; j < number; ++j) {
                
                std::string name, job;
                uint64_t passport;
                int age;

                std::cout << "Enter name: ";
                std::getline(std::cin, name);
                std::cout << "Enter age: ";
                std::cin >> age;
                std::cout << "Enter passport: ";
                std::cin >> passport;
                std::cin.ignore();
                std::cout << "Enter job: ";
                std::getline(std::cin, job);

                persons.push_back(std::make_shared<Person>(name, age, job, passport));
            }

            town.addFamily(std::make_shared<Family>(persons, address, number));
            std::cout << "Family added successfully!\n";
            break;
        }
        case ViewAllFamilies:
            town.showDataTown();
            break;
        case ExitMenu:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}
