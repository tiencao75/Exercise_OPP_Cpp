#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>
#include <iostream>
#include <functional>

class InvalidNameException : public std::exception {
private:
    std::string message;
public:
    InvalidNameException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class InvalidDOBException : public std::exception {
private:
    std::string message;
public:
    InvalidDOBException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class InvalidYearException : public std::exception {
private:
    std::string message;
public:
    InvalidYearException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class InvalidLocationException : public std::exception {
private:
    std::string message;
public:
    InvalidLocationException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

// Validation and Input Handling Class
class ExceptionHandler {
public:
    static void validateName(const std::string& name);
    static void validateID(const std::string& id);
    static void validateDOB(const std::string& dob);
    static void validateYear(int year);
    static void validateLocation(const std::string& location);

    static std::string handleStringInput(const std::function<void(const std::string&)>& validator, const std::string& prompt);
    static int handleIntegerInput(const std::function<void(int)>& validator, const std::string& prompt);
};

#endif // EXCEPTIONS_HPP
