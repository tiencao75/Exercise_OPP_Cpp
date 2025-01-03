#include"CandidateA.hpp"

CandidateA::CandidateA(string id, string name, string address, int priority)
    : Candidate(id, name, address, priority) {}

void CandidateA::showInfo() {
    Candidate::showInfo();
    cout << ", Subject: " << monToan << " - " << monLy << " - " << monHoa << endl;
}