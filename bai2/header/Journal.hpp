#ifndef JOURNAL_HPP
#define JOURNAL_HPP

#include "Document.hpp"

class Journal : public Document {
private:
    int issueNumber;
    string monthIssue;

public:
    Journal(const string& id, const string& publisher, int numberOfReleases, int issueNumber, string monthIssue);

    void setIssueNumber(int issueNumber);
    int getIssueNumber() const;

    void setMonthIssue(string monthIssue);
    string getMonthIssue() const;

    void showInfo() const override;
};

#endif
