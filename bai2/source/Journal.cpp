#include "Journal.hpp"
#include <iostream>
using namespace std;

Journal::Journal(const string& id, const string& publisher, int numberOfReleases, int issueNumber, string monthIssue)
    : Document(id, publisher, numberOfReleases), issueNumber(issueNumber), monthIssue(monthIssue) {}

void Journal::setIssueNumber(int issueNumber) { this->issueNumber = issueNumber; }
int Journal::getIssueNumber() const { return issueNumber; }

void Journal::setMonthIssue(string monthIssue) { this->monthIssue = monthIssue; }
string Journal::getMonthIssue() const { return monthIssue; }

void Journal::showInfo() const {
    cout << "Journal{"
         << "issueNumber=" << issueNumber << ", monthIssue=" << monthIssue
         << ", id='" << id << "', publisher='" << publisher << "', numberOfReleases=" << numberOfReleases << "}" << endl;
}
