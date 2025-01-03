#include "Engineer.hpp"

Engineer::Engineer(string name, int age, string gender, string address, string branch)
    : Officer(name, age, gender, address), branch(branch) {}

string Engineer::getBranch() const { return branch; }
void Engineer::setBranch(const string &newBranch) { branch = newBranch; }

string Engineer::showInfo() const {
    return Officer::showInfo() + ", Branch: " + branch;
}