#ifndef NEWSPAPER_HPP
#define NEWSPAPER_HPP

#include "Document.hpp"

class Newspaper : public Document {
private:
    string dayIssue;

public:
    Newspaper(const string& id, const string& publisher, int numberOfReleases, string dayIssue);

    void setDayIssue(string dayIssue);
    string getDayIssue() const;

    void showInfo() const override;
};

#endif
