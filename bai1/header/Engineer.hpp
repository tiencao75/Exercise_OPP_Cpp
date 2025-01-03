#ifndef ENGINEER_HPP
#define ENGINEER_HPP

#include "Officer.hpp"
#include <string>
using namespace std;

class Engineer : public Officer {
private:
    string branch;

public:
    Engineer(string name, int age, string gender, string address, string branch);
    string getBranch() const;
    void setBranch(const string &newBranch);
    string showInfo() const override;
};

#endif
