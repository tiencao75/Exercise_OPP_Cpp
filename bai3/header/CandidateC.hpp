#ifndef CANDIDATEC_HPP
#define CANDIDATEC_HPP

#include<iostream>
#include"Candidate.hpp"

using namespace std;
class CandidateC : public Candidate{
private:
    string monVan = "Mon Van";
    string monSu = "Mon Su";
    string monDia = "Mon Dia";
public:
    CandidateC(string id, string name, string address, int priority);
    void showInfo();
};

#endif