#include "Officer.hpp"

Officer::Officer(string name, int age, string gender, string address)
    : name(name), age(age), gender(gender), address(address) {}

string Officer::getName() const {
    return name;
}

void Officer::setName(const string &newName) {
    name = newName;
}

int Officer::getAge() const {
    return age;
}

void Officer::setAge(int newAge) {
    age = newAge;
}

string Officer::getGender() const {
    return gender;
}

void Officer::setGender(const string &newGender) {
    gender = newGender;
}

string Officer::getAddress() const {
    return address;
}

void Officer::setAddress(const string &newAddress) {
    address = newAddress;
}

string Officer::showInfo() const {
    return "Name: " + name + ", Age: " + to_string(age) + ", Gender: " + gender + ", Address: " + address;
}
