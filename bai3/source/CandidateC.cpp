#include"CandidateC.hpp"

CandidateC::CandidateC (string id, string name, string address, int priority)
: Candidate::Candidate(id, name, address, priority) {}

void CandidateC::showInfo(){
    Candidate::showInfo();
    cout << ", Subject: " << monVan << " - " << monSu << " - " << monDia << endl;
}