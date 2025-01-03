#ifndef FRESHER_HPP
#define FRESHER_HPP
#include "Employee.hpp"

class Fresher : public Employee {
private:
    std::string graduationDate;
    std::string graduationRank;
    std::string education;

public:
    Fresher(const std::string& id, const std::string& name, const std::string& birthDay, const std::string& phone,
     const std::string& email, const std::string& gradDate, const std::string& rank, const std::string& edu);
    ~Fresher();

    std::string getGraduationDate() const;
    void setGraduationDate(const std::string& date);

    std::string getGraduationRank() const;
    void setGraduationRank(const std::string& rank);

    std::string getEducation() const;
    void setEducation(const std::string& edu);

    void showInfo() const override;
    std::string gettype() override;
};

#endif // FRESHER_HPP