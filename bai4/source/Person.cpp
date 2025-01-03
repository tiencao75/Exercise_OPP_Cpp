#include "Person.hpp"
#include<string>

Person::Person(std::string name, int age, std::string job, uint64_t passport) 
    : name(name), age(age), job(job), passport(passport) {}

Person::~Person(){}

std::string Person::getName() {
    return name;
}

void Person::setName(std::string name) {
    this->name = name;
}

int Person::getAge() {
    return age;
}

void Person::setAge(int age) {
    this->age = age;
}

std::string Person::getJob() {
    return job;
}

void Person::setJob(std::string job) {
    this->job = job;
}

uint64_t Person::getPassport() {
    return passport;
}

void Person::setPassport(uint64_t passport) {
    this->passport = passport;
}

std::string Person::showInfo() {
    return "Person{name='" + name + "', age=" + std::to_string(age) +
           ", job='" + job + "', passport='" + std::to_string(passport) + "'}";
}
