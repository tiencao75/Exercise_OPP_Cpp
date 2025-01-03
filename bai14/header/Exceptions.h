#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
#include <iostream>
#include <functional>

class ExceptionHandler {
public:
    static std::string handleFullNameInput(const std::function<void(const std::string&)>& validator);
    static std::string handleDOBInput(const std::function<void(const std::string&)>& validator);
    static std::string handlePhoneNumberInput(const std::function<void(const std::string&)>& validator);
};

class InvalidFullNameException : public std::exception {
private:
    std::string message;
public:
    InvalidFullNameException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class InvalidDOBException : public std::exception {
private:
    std::string message;
public:
    InvalidDOBException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class InvalidPhoneNumberException : public std::exception {
private:
    std::string message;
public:
    InvalidPhoneNumberException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

#endif // EXCEPTION_H


