#include "Exceptions.hpp"
#include <regex>

// Birthday Validation
bool ExceptionHandler::validateDate(const std::string& birthday) {
    std::regex dateRegex(R"(^\d{2}/\d{2}/\d{4}$)"); // Format: dd/MM/yyyy
    if (!std::regex_match(birthday, dateRegex)) {
        return false;
    }

    int day, month, year;
    sscanf(birthday.c_str(), "%d/%d/%d", &day, &month, &year);

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
            return false;
        }
    }

    return true;
}

// Phone Number Validation
bool ExceptionHandler::validatePhone(const std::string& phone) {
    std::regex phoneRegex(R"(^\+?[0-9]{10,15}$)"); // Allows optional "+" and 10-15 digits
    return std::regex_match(phone, phoneRegex);
}

// Email Validation
bool ExceptionHandler::validateEmail(const std::string& email) {
    std::regex emailRegex(R"(^[\w.%+-]+@[\w.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, emailRegex);
}

// Full Name Validation
bool ExceptionHandler::validateFullName(const std::string& name) {
    std::regex nameRegex(R"(^[a-zA-Z\s]+$)"); // Allows only letters and spaces
    return !name.empty() && name.length() <= 100 && std::regex_match(name, nameRegex);
}