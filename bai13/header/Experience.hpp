#ifndef EXPERIENCE_HPP
#define EXPERIENCE_HPP
#include "Employee.hpp"

class Experience : public Employee {
private:
    int expInYear;
    std::string proSkill;

public:
    Experience(const std::string& id, const std::string& name, const std::string& birthDay,
     const std::string& phone, const std::string& email, int exp, const std::string& skill);
    ~Experience();

    int getExpInYear() const;
    void setExpInYear(int exp);

    std::string getProSkill() const;
    void setProSkill(const std::string& skill);

    void showInfo() const override;
    std::string gettype() override;
};

#endif // EXPERIENCE_HPP