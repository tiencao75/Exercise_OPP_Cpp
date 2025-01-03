#include "Employee.hpp"
#include <memory>

int Employee::employeeCount = 0;

Employee::Employee(const std::string& id, const std::string& name, const std::string& birthDay, const std::string& phone, const std::string& email, int type)
    : id(id), fullName(name), birthDay(birthDay), phone(phone), email(email), employeeType(type) {
    ++employeeCount;
}

Employee::~Employee() {}

std::string Employee::getId() const { return id; }
void Employee::setId(const std::string& id) { this->id = id; }

std::string Employee::getFullName() const { return fullName; }
void Employee::setFullName(const std::string& name) { fullName = name; }

std::string Employee::getBirthDay() const { return birthDay; }
void Employee::setBirthDay(const std::string& birthDay) { this->birthDay = birthDay; }

std::string Employee::getPhone() const { return phone; }
void Employee::setPhone(const std::string& phone) { this->phone = phone; }

std::string Employee::getEmail() const { return email; }
void Employee::setEmail(const std::string& email) { this->email = email; }

int Employee::getEmployeeType() const { return employeeType; }
void Employee::setEmployeeType(int type) { employeeType = type; }

void Employee::addCertificate(std::shared_ptr<Certificate> cert) {
    certificates.push_back(cert);
}

bool Employee::removeCertificate(const std::string& certId) {
    for (auto it = certificates.begin(); it != certificates.end(); it++)
    {
        if ((*it)->getCertificateID() == certId)
        {
            certificates.erase(it);
            std::cout << "Certificate deleted successfully.\n";   
            return true;
        }
    }
    std::cout << "Certificate not found.\n";
    return false;
}

void Employee::showCertificates() const {
    for (const auto& cert : certificates) {
        cert->showCertificateInfo();
    }
}

int Employee::getEmployeeCount() { return employeeCount; }