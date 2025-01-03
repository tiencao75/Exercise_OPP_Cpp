#include "Newspaper.hpp"
#include <iostream>
using namespace std;

Newspaper::Newspaper(const string& id, const string& publisher, int numberOfReleases, string dayIssue)
    : Document(id, publisher, numberOfReleases), dayIssue(dayIssue) {}

void Newspaper::setDayIssue(string dayIssue) { this->dayIssue = dayIssue; }
string Newspaper::getDayIssue() const { return dayIssue; }

void Newspaper::showInfo() const {
    cout << "Newspaper{"
         << "dayIssue=" << dayIssue
         << ", id='" << id << "', publisher='" << publisher << "', numberOfReleases=" << numberOfReleases << "}" << endl;
}
