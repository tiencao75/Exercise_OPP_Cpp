#ifndef MANAGER_OFFICER_HPP
#define MANAGER_OFFICER_HPP

#include "Officer.hpp"
#include <vector>
#include <memory>
#include <string>
using namespace std;

class ManagerOfficer {
private:
    vector<Officer*> officerList;

public:
    ~ManagerOfficer();
    void addOfficerNormal(Officer* officer);
    void searchOfficerByName(const string &name) const;
    void showAllOfficers() const;
};

#endif