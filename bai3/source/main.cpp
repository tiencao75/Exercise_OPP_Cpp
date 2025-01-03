#include<iostream>
#include"Candidate.hpp"
#include"CandidateA.hpp"
#include"CandidateB.hpp"
#include"CandidateC.hpp"
#include"ManagerCandidate.hpp"

enum mode {
    insert = 1,
    show,
    searchId,
    exit_code 
};

enum blockOfStudy{
    blockA = 1,
    blockB,
    blockC
};

int main() {
    ManagerCandidate manager;
    int choice;

    do
    {
        cout << "Application Manager Candidate" << endl;
        cout << "Enter 1: To insert candidate" << endl;
        cout << "Enter 2: To show candidate information" << endl;
        cout << "Enter 3: To search candidate by id" << endl;
        cout << "Enter 4: To exit" << endl;

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case insert:
        {
            cout << "Enter 1: to insert candidates of block A" << endl;
            cout << "Enter 2: to insert candidates of block B" << endl;
            cout << "Enter 3: to insert candidates of block C" << endl;
            int type;
            cin >> type;
            cin.ignore();

                string id, name, address;
                int priority;
                cout << "Enter ID: ";
                getline(cin, id);
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter priority: ";
                cin >> priority;
                cin.ignore();
            if (type == blockA) {
                manager.add(make_shared<CandidateA>( id, name, address, priority));
            } else if (type == blockB) {
                manager.add(make_shared<CandidateB>( id, name, address, priority));
            } else if (type == blockC) {
                manager.add(make_shared<CandidateC>( id, name, address, priority));
            }
            break;
        }   
        case show:
        {
            manager.showInfo();
            break;
        } 
        case searchId:
        {
            string idSearch;
            cout << "Enter id to search: ";
            getline(cin, idSearch);
            manager.searchById(idSearch);
            break;
        } 
        case exit_code:
        {
            cout << "Exit program." << endl;
            break;
        }         
        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    } while (choice != exit_code);

    return 0;
}