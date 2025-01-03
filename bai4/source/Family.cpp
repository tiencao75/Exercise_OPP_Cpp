#include "Family.hpp"

Family::Family(std::vector<std::shared_ptr<Person>> persons, std::string address, int memberNumber) 
    : personList(persons), address(address), memberNumber(memberNumber) {}

std::string Family::getAddress() {
    return address;
}

void Family::setAddress(std::string address) {
    this->address = address;
}
int Family::getMemberNumber(){
    return memberNumber;
};

void Family::setMenberNumber(int number){
    this->memberNumber = number;
};

std::string Family::showInfor() {
    std::string result = "Family{persons=[";
    for (const auto& person : personList) {
        result += person->showInfo() + ", ";
    }
    result += "], address='" + address + "'}";
    return result;
}
