#include<iostream>
#include <regex>
#include"ManagerEmployee.hpp"
#include "Exceptions.hpp"


ManagerEmployee::ManagerEmployee(){};
ManagerEmployee::~ManagerEmployee(){};

void ManagerEmployee::addEmployee(std::shared_ptr<Employee> employee){
    employeeList.push_back(employee);
};
bool ManagerEmployee::removeEmployeeById(const std::string&  id){
    for (auto it = employeeList.begin(); it != employeeList.end(); it++)
    {
        if ((*it)->getId() == id)
        {
            employeeList.erase(it);
            std::cout << "Employee deleted successfully.\n";   
            return true;
        }
    }
    std::cout << "Employee not found.\n";
    return false;
};
void ManagerEmployee::updateEmployeeById(const std::string&  id){

    auto employee = searchEmployeeById(id); // Tìm nhân viên qua ID
    if (!employee) {
        std::cout << "Employee not found.\n";
        return;
    }

    int updateChoice;
    do {
        std::cout << "\nChoose information to update:\n";
        std::cout << "1. Name\n";
        std::cout << "2. Phone\n";
        std::cout << "3. Email\n";
        std::cout << "4. Birth Date\n";
        std::cout << "5. Certificates\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> updateChoice;

        std::cin.ignore(); // Xóa ký tự thừa trong buffer
        switch (updateChoice) {
        case 1: {
            std::string newName;
            std::cout << "Enter new name: ";
            std::getline(std::cin, newName);

            if (ExceptionHandler::validateDate(newName)) {
                employee->setFullName(newName);
                std::cout << "Name updated successfully.\n";
            } else {
                std::cout << "Invalid name format.\n";
            }
            break;
        }
        case 2: {
            std::string newPhone;
            std::cout << "Enter new phone: ";
            std::getline(std::cin, newPhone);

            if (ExceptionHandler::validatePhone(newPhone)) {
                employee->setPhone(newPhone);
                std::cout << "Phone updated successfully.\n";
            } else {
                std::cout << "Invalid phone format.\n";
            }
            break;
        }
        case 3: {
            std::string newEmail;
            std::cout << "Enter new email: ";
            std::getline(std::cin, newEmail);

            if (ExceptionHandler::validateEmail(newEmail)) {
                employee->setEmail(newEmail);
                std::cout << "Email updated successfully.\n";
            } else {
                std::cout << "Invalid email format.\n";
            }
            break;
        }
        case 4: {
            std::string newBirthDate;
            std::cout << "Enter new birth date (YYYY-MM-DD): ";
            std::getline(std::cin, newBirthDate);

            if (ExceptionHandler::validateDate(newBirthDate)) {
                employee->setBirthDay(newBirthDate);
                std::cout << "Birth date updated successfully.\n";
            } else {
                std::cout << "Invalid birth date format.\n";
            }
            break;
        }
        case 5: {
            char modifyCert = 'y';
            do {
                std::cout << "\nChoose action for certificates:\n";
                std::cout << "1. Add Certificate\n";
                std::cout << "2. Remove Certificate\n";
                std::cout << "3. View Certificates\n";
                std::cout << "4. Exit Certificate Management\n";
                int certChoice;
                std::cout << "Enter your choice: ";
                std::cin >> certChoice;

                std::cin.ignore(); // Xóa buffer trước khi nhập
                switch (certChoice) {
                case 1: {
                    std::string certID, certName, certRank, certDate;
                    std::cout << "Enter certificate ID: ";
                    std::getline(std::cin, certID);
                    std::cout << "Enter certificate name: ";
                    std::getline(std::cin, certName);
                    std::cout << "Enter certificate rank: ";
                    std::getline(std::cin, certRank);
                    std::cout << "Enter certificate date (YYYY-MM-DD): ";
                    std::getline(std::cin, certDate);

                    std::shared_ptr<Certificate> newCert = std::make_shared<Certificate>(certID, certName, certRank, certDate);
                    employee->addCertificate(newCert);
                    std::cout << "Certificate added successfully.\n";
                    break;
                }
                case 2: {
                    std::string certID;
                    std::cout << "Enter certificate ID to remove: ";
                    std::getline(std::cin, certID);

                    employee->removeCertificate(certID);
                    break;
                }
                case 3: {
                    std::cout << "Certificates:\n";
                    employee->showCertificates();
                    break;
                }
                case 4:
                    modifyCert = 'n';
                    break;
                default:
                    std::cout << "Invalid choice!\n";
                }
            } while (modifyCert == 'y' || modifyCert == 'Y');
            break;
        }
        case 6:
            std::cout << "Exiting update menu.\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (updateChoice != 6);
};
std::shared_ptr<Employee> ManagerEmployee::searchEmployeeById(const std::string&  id){
    for ( auto& employee : employeeList)
    {
        if (employee->getId() == id)
        {
            return employee;
        }
        
    }
    return nullptr;
};

void ManagerEmployee::showAllEmployee(){
    for ( auto &employee : employeeList)
    {
        employee->showInfo();
    }
};

void ManagerEmployee::showAllFresher(){
    for ( auto &employee : employeeList)
    {
        if (employee->gettype() == "Fresher")
        {
            employee->showInfo();
        }
    }
};

void ManagerEmployee::showAllExperience(){
    for ( auto &employee : employeeList)
    {
        if (employee->gettype() == "Experience")
        {
            employee->showInfo();
        }
    }
};

void ManagerEmployee::showAllIntern(){
    for ( auto &employee : employeeList)
    {
        if (employee->gettype() == "Intern")
        {
            employee->showInfo();
        }
    }
};
