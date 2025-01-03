#ifndef MANAGEREMPLOYEE_HPP
#define MANAGEREMPLOYEE_HPP
#include "Employee.hpp"
#include "Exceptions.hpp"
#include <vector>
#include <memory> 
#include <string>

class ManagerEmployee {
private:
    std::vector<std::shared_ptr<Employee>> employeeList;

public:
    ManagerEmployee();
    ~ManagerEmployee();

    void addEmployee(std::shared_ptr<Employee> employee);
    bool removeEmployeeById(const std::string& id);
    void updateEmployeeById(const std::string& id);
    std::shared_ptr<Employee> searchEmployeeById(const std::string& id);
    void showAllEmployee();
    void showAllFresher();
    void showAllExperience();
    void showAllIntern();
    
};

#endif // MANAGEREMPLOYEE_HPP