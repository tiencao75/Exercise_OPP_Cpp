#ifndef MANAGERDOCUMENT_HPP
#define MANAGERDOCUMENT_HPP

#include "Document.hpp"
#include <vector>
#include <memory>

class ManagerDocument {
private:
    vector<shared_ptr<Document>> documents;

public:
    void addDocument(shared_ptr<Document> document);
    bool deleteDocument(const string& id);
    void showInfo() const;
    void searchByBook() const;
    void searchByJournal() const;
    void searchByNewspaper() const;
};

#endif
