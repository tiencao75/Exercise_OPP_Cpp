#include "Book.hpp"
#include <iostream>
using namespace std;

Book::Book(const string& id, const string& publisher, int numberOfReleases, const string& author, int numberPage)
    : Document(id, publisher, numberOfReleases), author(author), numberPage(numberPage) {}

void Book::setAuthor(const string& author) { this->author = author; }
string Book::getAuthor() const { return author; }

void Book::setNumberPage(int numberPage) { this->numberPage = numberPage; }
int Book::getNumberPage() const { return numberPage; }

void Book::showInfo() const {
    cout << "Book{"
         << "author='" << author << "', numberPage=" << numberPage
         << ", id='" << id << "', publisher='" << publisher << "', numberOfReleases=" << numberOfReleases << "}" << endl;
}
