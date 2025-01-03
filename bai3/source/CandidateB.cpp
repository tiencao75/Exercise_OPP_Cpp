#include"CandidateB.hpp"


CandidateB::CandidateB(string id, string name, string address, int priority)
    : Candidate(id, name, address, priority){}

void CandidateB::showInfo(){
    Candidate::showInfo();
    cout << ", Subject: " << monToan << " - " << monHoa << " - " << monSinh << endl;
}