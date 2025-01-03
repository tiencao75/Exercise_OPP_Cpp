#include"ManagerCandidate.hpp"

void ManagerCandidate::add(shared_ptr<Candidate> candidate){
    candidateList.push_back(candidate);
}

void ManagerCandidate::showInfo(){
    for(const auto& candidate : candidateList){
        candidate->showInfo();
    }
}

void ManagerCandidate::searchById(string id){
    for ( auto it = candidateList.begin(); it != candidateList.end(); it ++)
    {
        if ((*it)->getId() == id )
        {
            return (*it)->showInfo();
        }
    }
    cout << "Employee not found.\n";
}


