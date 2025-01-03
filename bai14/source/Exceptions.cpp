#include "Exceptions.h"

std::string ExceptionHandler::handleFullNameInput(const std::function<void(const std::string&)>& validator) {
    std::string fullName;
    bool isValid = false;

    do {
        try {
            std::cout << "Enter full name (10-50 characters): ";
            std::getline(std::cin, fullName);
            validator(fullName); // Gọi hàm validate thông qua callback
            isValid = true;
        } catch (const InvalidFullNameException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
        }
    } while (!isValid);

    return fullName;
}

std::string ExceptionHandler::handleDOBInput(const std::function<void(const std::string&)>& validator) {
    std::string dob;
    bool isValid = false;

    do {
        try {
            std::cout << "Enter date of birth (dd/MM/YYYY): ";
            std::getline(std::cin, dob);
            validator(dob); // Gọi hàm validate thông qua callback
            isValid = true;
        } catch (const InvalidDOBException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
        }
    } while (!isValid);

    return dob;
}

std::string ExceptionHandler::handlePhoneNumberInput(const std::function<void(const std::string&)>& validator) {
    std::string phoneNumber;
    bool isValid = false;

    do {
        try {
            std::cout << "Enter phone number (10 digits, start with 090, 098, etc.): ";
            std::getline(std::cin, phoneNumber);
            validator(phoneNumber); // Gọi hàm validate thông qua callback
            isValid = true;
        } catch (const InvalidPhoneNumberException& e) {
            std::cerr << "Error: " << e.what() << "\nPlease try again.\n";
        }
    } while (!isValid);

    return phoneNumber;
}

