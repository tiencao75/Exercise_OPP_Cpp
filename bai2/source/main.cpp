#include "ManagerDocument.hpp"
#include "Document.hpp"
#include "Book.hpp"
#include "Journal.hpp"
#include "Newspaper.hpp"
#include <iostream>
using namespace std;

enum DocumentMenuOption {
    InsertDocument = 1,
    SearchDocumentByCategory,
    ShowInformationDocuments,
    RemoveDocumentById,
    ExitApplication
};

enum DocumentType {
    BookChoice = 'a',
    NewspaperChoice = 'b',
    JournalChoice = 'c'
};

int main() {
    ManagerDocument manager;
    int choice;

    while (true) {
        cout << "Application Manager Document" << endl;
        cout << "Enter 1: To insert document" << endl;
        cout << "Enter 2: To search document by category" << endl;
        cout << "Enter 3: To show information documents" << endl;
        cout << "Enter 4: To remove document by id" << endl;
        cout << "Enter 5: To exit" << endl;

        cin >> choice;
        cin.ignore();

        if (choice == InsertDocument) {
            cout << "Enter a: to insert Book" << endl;
            cout << "Enter b: to insert Newspaper" << endl;
            cout << "Enter c: to insert Journal" << endl;
            char type;
            cin >> type;
            cin.ignore();

            if (type == BookChoice) {
                string id, publisher, author;
                int numberOfReleases, numberPage;
                cout << "Enter ID: ";
                getline(cin, id);
                cout << "Enter publisher: ";
                getline(cin, publisher);
                cout << "Enter numberOfReleases: ";
                cin >> numberOfReleases;
                cin.ignore();
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter page number: ";
                cin >> numberPage;
                manager.addDocument(make_shared<Book>(id, publisher, numberOfReleases, author, numberPage));
            } else if (type == NewspaperChoice) {
                string id, publisher;
                int numberOfReleases;
                string dayIssue;
                cout << "Enter ID: ";
                getline(cin, id);
                cout << "Enter publisher: ";
                getline(cin, publisher);
                cout << "Enter numberOfReleases: ";
                cin >> numberOfReleases;
                cin.ignore();
                cout << "Enter day issue: ";
                getline(cin, dayIssue);
                manager.addDocument(make_shared<Newspaper>(id, publisher, numberOfReleases, dayIssue));
            } else if (type == JournalChoice) {
                string id, publisher;
                int numberOfReleases;
                int issueNumber;
                string monthIssue;
                cout << "Enter ID: ";
                getline(cin, id);
                cout << "Enter publisher: ";
                getline(cin, publisher);
                cout << "Enter numberOfReleases: ";
                cin >> numberOfReleases;
                cout << "Enter issue number: ";
                cin >> issueNumber;
                cin.ignore();
                cout << "Enter month issue: ";
                getline(cin, monthIssue);
                manager.addDocument(make_shared<Journal>(id, publisher, numberOfReleases, issueNumber, monthIssue));
            }
        } else if (choice == SearchDocumentByCategory) {
            cout << "Enter a to search book" << endl;
            cout << "Enter b to search newspaper" << endl;
            cout << "Enter c to search journal" << endl;
            char searchType;
            cin >> searchType;

            if (searchType == BookChoice) {
                manager.searchByBook();
            } else if (searchType == NewspaperChoice) {
                manager.searchByNewspaper();
            } else if (searchType == JournalChoice) {
                manager.searchByJournal();
            }
        } else if (choice == ShowInformationDocuments) {
            manager.showInfo();
        } else if (choice == RemoveDocumentById) {
            string id;
            cout << "Enter id to remove: ";
            getline(cin, id);
            if (manager.deleteDocument(id)) {
                cout << "Success" << endl;
            } else {
                cout << "Fail" << endl;
            }
        } else if (choice == ExitApplication) {
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
