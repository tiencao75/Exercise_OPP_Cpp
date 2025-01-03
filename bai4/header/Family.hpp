#ifndef FAMILY_HPP
#define FAMILY_HPP

#include <vector>
#include <memory>
#include <string>
#include "Person.hpp"

class Family {
private:
    std::vector<std::shared_ptr<Person>> personList;
    std::string address;
    int memberNumber;

public:
    Family(std::vector<std::shared_ptr<Person>> personList, std::string address, int memberNumber);
    
    std::string getAddress();
    void setAddress(std::string address);

    int getMemberNumber();
    void setMenberNumber(int number);

    std::string showInfor();
};

#endif // FAMILY_HPP
