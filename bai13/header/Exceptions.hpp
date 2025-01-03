#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include <exception>

// Exception Classes
class BirthDayException : public std::exception {
private:
    std::string message;
public:
    explicit BirthDayException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class PhoneException : public std::exception {
private:
    std::string message;
public:
    explicit PhoneException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class EmailException : public std::exception {
private:
    std::string message;
public:
    explicit EmailException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class FullNameException : public std::exception {
private:
    std::string message;
public:
    explicit FullNameException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

// Exception Handler Class
class ExceptionHandler {
public:
    static bool validateDate(const std::string& birthday);
    static bool validatePhone(const std::string& phone);
    static bool validateEmail(const std::string& email);
    static bool validateFullName(const std::string& name);
};

#endif // EXCEPTIONS_HPP
