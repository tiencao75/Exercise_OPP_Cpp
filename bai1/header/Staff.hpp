#ifndef STAFF_HPP
#define STAFF_HPP

#include "Officer.hpp"
#include <string>
using namespace std;

class Staff : public Officer {
private:
    string task;

public:
    Staff(string name, int age, string gender, string address, string task);
    string getTask() const;
    void setTask(const string &newTask);
    string showInfo() const override;
};

#endif