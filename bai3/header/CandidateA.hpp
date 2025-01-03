#ifndef CANDIDATEA_HPP
#define CANDIDATEA_HPP

#include<iostream>
#include"Candidate.hpp"
using namespace std;
class CandidateA : public Candidate {
private:
    string monToan = "Mon Toan";
    string monLy = "Mon Ly";
    string monHoa = "Mon Hoa";
public:
    CandidateA(string id, string name, string address, int priority);
    void showInfo();
};

#endif