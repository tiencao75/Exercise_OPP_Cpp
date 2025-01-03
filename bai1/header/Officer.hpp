#ifndef OFFICER_HPP
#define OFFICER_HPP

#include <string>
using namespace std;

class Officer {
protected:
    string name;
    int age;
    string gender;
    string address;

public:
    Officer(string name, int age, string gender, string address);
    virtual ~Officer() = default;

    string getName() const;
    void setName(const string &newName);

    int getAge() const;
    void setAge(int newAge);

    string getGender() const;
    void setGender(const string &newGender);

    string getAddress() const;
    void setAddress(const string &newAddress);

    virtual string showInfo() const;
};

#endif
