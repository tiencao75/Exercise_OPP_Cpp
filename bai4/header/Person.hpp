#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <cstdint>

class Person {
private:
    std::string name;
    int age;
    std::string job;
    int passport;

public:
    Person(std::string name, int age, std::string job, uint64_t passport);
    ~Person();

    std::string getName();
    void setName(std::string name);

    int getAge();
    void setAge(int age);

    std::string getJob();
    void setJob(std::string job);

    uint64_t getPassport();
    void setPassport(uint64_t passport);

    std::string showInfo();
};

#endif // PERSON_HPP
