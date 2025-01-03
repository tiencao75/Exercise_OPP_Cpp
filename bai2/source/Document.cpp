#include "Document.hpp"
#include <iostream>
using namespace std;

Document::Document(const string& id, const string& publisher, int numberOfReleases)
    : id(id), publisher(publisher), numberOfReleases(numberOfReleases) {}

Document::~Document() {}

string Document::getId() const { return id; }
void Document::setId(const string& id) { this->id = id; }

string Document::getPublisher() const { return publisher; }
void Document::setPublisher(const string& publisher) { this->publisher = publisher; }

int Document::getNumberOfReleases() const { return numberOfReleases; }
void Document::setNumberOfReleases(int numberOfReleases) { this->numberOfReleases = numberOfReleases; }
