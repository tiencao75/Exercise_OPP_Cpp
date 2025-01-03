#include "Certificate.hpp"

Certificate::Certificate(const std::string& id, const std::string& name, const std::string& rank, const std::string& date)
    : certificateID(id), certificateName(name), certificateRank(rank), certificateDate(date) {}

Certificate::~Certificate() {}

std::string Certificate::getCertificateID() const { return certificateID; }
void Certificate::setCertificateID(const std::string& id) { certificateID = id; }

std::string Certificate::getCertificateName() const { return certificateName; }
void Certificate::setCertificateName(const std::string& name) { certificateName = name; }

std::string Certificate::getCertificateRank() const { return certificateRank; }
void Certificate::setCertificateRank(const std::string& rank) { certificateRank = rank; }

std::string Certificate::getCertificateDate() const { return certificateDate; }
void Certificate::setCertificateDate(const std::string& date) { certificateDate = date; }

void Certificate::showCertificateInfo() const {
    std::cout << "Certificate [ID: " << certificateID << ", Name: " << certificateName
              << ", Rank: " << certificateRank << ", Date: " << certificateDate << "]\n";
}