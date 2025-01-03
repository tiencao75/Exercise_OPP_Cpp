#include "ManagerOfficer.hpp"
#include <iostream>
using namespace std;


ManagerOfficer::~ManagerOfficer(){
        //Giai phong bo nho cho tat ca officer trong officerLisst
        for ( auto officer : officerList)
        {
            delete officer;
        }
    }

void ManagerOfficer::addOfficerNormal(Officer* officer){
    officerList.push_back(officer);
}

void ManagerOfficer::searchOfficerByName(const string &name) const{
    for (const auto officer : officerList)
    {
        if (officer->getName().find(name) != string::npos)
        {
            cout << officer->showInfo() << endl;
        }
    }
}

void ManagerOfficer::showAllOfficers() const {
    for (const auto &officer : officerList) {
        cout << officer->showInfo() << endl;
    }
}
