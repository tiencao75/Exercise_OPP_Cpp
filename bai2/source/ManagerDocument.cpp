#include "ManagerDocument.hpp"
#include "Book.hpp"
#include "Journal.hpp"
#include "Newspaper.hpp"
#include <iostream>
using namespace std;

void ManagerDocument::addDocument(shared_ptr<Document> document) {
    documents.push_back(document);
}

bool ManagerDocument::deleteDocument(const string& id) {
    for (auto it = documents.begin(); it != documents.end(); ++it) {
        if ((*it)->getId() == id) {
            documents.erase(it);
            return true;
        }
    }
    return false;
}

void ManagerDocument::showInfo() const {
    for (const auto& doc : documents) {
        doc->showInfo();
    }
}

void ManagerDocument::searchByBook() const {
    for (const auto& doc : documents) {
        if (dynamic_cast<Book*>(doc.get())) {
            doc->showInfo();
        }
    }
}

void ManagerDocument::searchByJournal() const {
    for (const auto& doc : documents) {
        if (dynamic_cast<Journal*>(doc.get())) {
            doc->showInfo();
        }
    }
}

void ManagerDocument::searchByNewspaper() const {
    for (const auto& doc : documents) {
        if (dynamic_cast<Newspaper*>(doc.get())) {
            doc->showInfo();
        }
    }
}
