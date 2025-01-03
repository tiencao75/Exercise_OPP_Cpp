#ifndef CANDIDATE_HPP
#define CANDIDATE_HPP

#include<iostream>
using namespace std;
class Candidate {
private:
    string id;
    string name;
    string address;
    int priority;
public:
    Candidate(string id, string name, string address, int priority);
    virtual ~Candidate();
    string getId();
    void setId(string newId);
    string getName();
    void setName(string newName);
    string getAddress();
    void setAddress(string newAddress);
    int getPriority();
    void setPriority(int newPriority);
    virtual void showInfo();
};

#endif