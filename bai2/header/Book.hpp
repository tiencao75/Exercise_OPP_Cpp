#ifndef BOOK_HPP
#define BOOK_HPP

#include "Document.hpp"

class Book : public Document {
private:
    string author;
    int numberPage;

public:
    Book(const string& id, const string& publisher, int numberOfReleases, const string& author, int numberPage);

    void setAuthor(const string& author);
    string getAuthor() const;

    void setNumberPage(int numberPage);
    int getNumberPage() const;

    void showInfo() const override;
};

#endif
