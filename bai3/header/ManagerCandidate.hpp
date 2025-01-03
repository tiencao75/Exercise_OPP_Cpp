#ifndef MANAGERCANDIDATE
#define MANAGERCANDIDATE

#include<vector>
#include<memory>
#include"Candidate.hpp"
using namespace std;

class ManagerCandidate{
private:
    vector<shared_ptr<Candidate>> candidateList;
public:
    void add(shared_ptr<Candidate> candidate);
    void showInfo();
    void searchById(string id);
};

#endif