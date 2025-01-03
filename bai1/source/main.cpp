#include "Engineer.hpp"
#include "Worker.hpp"
#include "Staff.hpp"
#include "ManagerOfficer.hpp"
#include <iostream>
#include <memory>
using namespace std;

enum MenuOption {
    InsertOfficer = 1,
    SearchOfficerByName,
    ShowAllOfficers,
    Exit
};

int main() {
    ManagerOfficer manager;
    int choice;
    string name;
    enum OfficerType{
        ChoiceEngineer = 1,
        ChoiceStaff,
        ChoiceWorker
    };
    do
    {
        cout << "\nApplication Manager Officer\n";
        cout << "1. Insert Officer\n";
        cout << "2. Search Officer by Name\n";
        cout << "3. Show All Officers\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        int choiceOfficer;
        
        switch (choice)
        {
        case InsertOfficer:
            cout << "Enter 1: to Insert Engineer\n";
            cout << "Enter 2: to Insert Staff\n";
            cout << "Enter 3: to Insert Worker\n";
            cin >> choiceOfficer;
            cin.ignore();
            if (choiceOfficer == ChoiceEngineer || choiceOfficer == ChoiceStaff || choiceOfficer == ChoiceWorker){
                string name, gender, address;
                int age;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter gender: ";
                getline(cin, gender);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                if (choiceOfficer == ChoiceEngineer)
                {
                    string branch;
                    cout << "Enter brand: ";
                    getline(cin, branch);
                    manager.addOfficerNormal(new Engineer(name, age, gender, address, branch));
                } else if (choiceOfficer == ChoiceStaff)
                {
                    string task;
                    cout << "Enter task: ";
                    getline(cin, task);
                    manager.addOfficerNormal(new Staff(name, age, gender, address, task));
                }
                else
                {
                    int level;
                    cout << "Enter level: ";
                    cin >> level;
                    manager.addOfficerNormal(new Worker(name, age, gender, address, level));
                }
            }
            else {
                cout << "Invalid input, please try again!\n";
            }
            break;

        case SearchOfficerByName:
            cout << "Enter name to search: ";
            getline(cin, name);
            manager.searchOfficerByName(name);
            break;
        case ShowAllOfficers:
            manager.showAllOfficers();
            break;
        case Exit:
            break;
        default:
            cout << "Invalid choice! \n";
            break;
        }
    } while (choice != 4);

    return 0;
}
