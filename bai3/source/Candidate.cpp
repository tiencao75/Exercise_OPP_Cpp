#include"Candidate.hpp"

Candidate::Candidate(string id, string name, string address, int priority)
: id(id), name(name), address(address), priority(priority) {}

Candidate::~Candidate(){}

string Candidate::getId() {return id;}
void Candidate::setId(string newId){this->id = newId;}

string Candidate::getName() {return name;}
void Candidate::setName(string newName){this->name = newName;}

string Candidate::getAddress() {return address;}
void Candidate::setAddress(string newAddress){this->address = newAddress;}

int Candidate::getPriority(){return priority;}
void Candidate::setPriority(int newPriority){this->priority = newPriority;}

void Candidate::showInfo(){
    cout << "Id: " << id << ", Name: " << name << ", Address: " << address << ", Priority: " << priority << endl;
}
