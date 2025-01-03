#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <string>
#include <vector>
#include "Certificate.hpp"
#include <iostream>
#include <memory>

class Employee {
protected:
    std::string id;
    std::string fullName;
    std::string birthDay;
    std::string phone;
    std::string email;
    int employeeType;
    std::vector<std::shared_ptr<Certificate>> certificates;
    static int employeeCount;
public:
    Employee(const std::string& id, const std::string& name, const std::string& birthDay, 
    const std::string& phone, const std::string& email, int type);
    virtual ~Employee();

    std::string getId() const;
    void setId(const std::string& id);

    std::string getFullName() const;
    void setFullName(const std::string& name);

    std::string getBirthDay() const;
    void setBirthDay(const std::string& birthDay);

    std::string getPhone() const;
    void setPhone(const std::string& phone);

    std::string getEmail() const;
    void setEmail(const std::string& email);

    int getEmployeeType() const;
    void setEmployeeType(int type);

    void addCertificate(std::shared_ptr<Certificate> cert);
    bool removeCertificate(const std::string& certID);
    void showCertificates() const;

    virtual void showInfo() const = 0; // Pure virtual method for polymorphism
    static int getEmployeeCount();
    virtual std::string gettype() = 0; // Abstract Method
};

#endif // EMPLOYEE_HPP