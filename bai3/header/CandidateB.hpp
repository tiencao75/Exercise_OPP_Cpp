#ifndef CANDIDATEB_HPP
#define CANDIDATEB_HPP

#include<iostream>
#include"Candidate.hpp"
using namespace std;
class CandidateB :  public Candidate{
private:
    string monToan = "Mon Toan";
    string monHoa = "Mon Hoa";
    string monSinh = "Mon Sinh";
public:
    CandidateB(string id, string name, string address, int priority);
    void showInfo();
};

#endif