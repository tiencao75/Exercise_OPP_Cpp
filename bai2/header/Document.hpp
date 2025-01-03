#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>
using namespace std;

class Document {
protected:
    string id;
    string publisher;
    int numberOfReleases;

public:
    Document(const string& id, const string& publisher, int numberOfReleases);
    virtual ~Document();

    string getId() const;
    void setId(const string& id);

    string getPublisher() const;
    void setPublisher(const string& publisher);

    int getNumberOfReleases() const;
    void setNumberOfReleases(int numberOfReleases);

    virtual void showInfo() const = 0;
};

#endif
