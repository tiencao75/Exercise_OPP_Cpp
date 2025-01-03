#include "Exception.hpp"
#include <regex>
#include <limits>

void ExceptionHandler::validateName(const std::string& name) {
    std::regex nameRegex(R"(^[a-zA-Z\s]+$)"); // Allows only letters and spaces
    if (name.length() < 1 || name.length() > 50 || !std::regex_match(name, nameRegex)) {
        throw InvalidNameException("Name must be between 1 and 50 characters and contain only letters and spaces.");
    }
}

void ExceptionHandler::validateID(const std::string& id) {
    std::regex idRegex(R"(^[a-zA-Z0-9]+$)"); // Allows only letters and digits
    if (id.length() < 1 || id.length() > 50 || !std::regex_match(id, idRegex)) {
        throw std::invalid_argument("ID must be between 1 and 50 characters and contain only letters and digits.");
    }
}

void ExceptionHandler::validateDOB(const std::string& dob) {
    std::regex dateRegex(R"(^\d{2}/\d{2}/\d{4}$)");
    if (!std::regex_match(dob, dateRegex)) {
        throw InvalidDOBException("Date of birth must be in the format dd/MM/YYYY.");
    }

    // Additional validation for date values
    int day, month, year;
    sscanf(dob.c_str(), "%d/%d/%d", &day, &month, &year);

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        throw InvalidDOBException("Invalid date values in the date of birth.");
    }

    // Check for days in each month
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        throw InvalidDOBException("Invalid day value for the given month.");
    }

    // Check for February
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
            throw InvalidDOBException("Invalid day value for February.");
        }
    }
}

void ExceptionHandler::validateYear(int year) {
    // Check if the year is a 4-digit number
    if (year < 1000 || year > 9999) {
        throw InvalidYearException("Invalid year: Year must be a 4-digit number.");
    }

    // Check if the year is in the valid range (1900–2100)
    if (year < 1900 || year > 2100) {
        throw InvalidYearException("Invalid year: Year must be between 1900 and 2100.");
    }
}

void ExceptionHandler::validateLocation(const std::string& location) {
    // Check if the location is empty or contasins only whitespace
    if (location.empty() || std::all_of(location.begin(), location.end(), isspace)) {
        throw InvalidLocationException("Invalid location: Location cannot be empty or whitespace.");
    }
    // Optional: Add regex or other validation rules for specific location formats
}

// Input Handling
std::string ExceptionHandler::handleStringInput(const std::function<void(const std::string&)>& validator, const std::string& prompt) {
    std::string input;
    while (true) {
        try {
            std::cout << prompt;
            std::getline(std::cin, input);
            validator(input);
            return input;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << " Please try again.\n";
        }
    }
}

int ExceptionHandler::handleIntegerInput(const std::function<void(int)>& validator, const std::string& prompt) {
    int input;
    while (true) {
        try {
            std::cout << prompt;
            std::cin >> input;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Invalid input. Must be an integer.");
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            validator(input);
            return input;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << " Please try again.\n";
        }
    }
}

