#ifndef INTERN_HPP
#define INTERN_HPP
#include "Employee.hpp"

class Intern : public Employee {
private:
    std::string majors;
    std::string semester;
    std::string universityName;

public:
    Intern(const std::string& id, const std::string& name, const std::string& birthDay, const std::string& phone,
     const std::string& email, const std::string& majors, const std::string& semester, const std::string& uniName);
    ~Intern();

    std::string getMajors() const;
    void setMajors(const std::string& majors);

    std::string getSemester() const;
    void setSemester(const std::string& semester);

    std::string getUniversityName() const;
    void setUniversityName(const std::string& uniName);

    void showInfo() const override;
    std::string gettype() override;
};

#endif // INTERN_HPP