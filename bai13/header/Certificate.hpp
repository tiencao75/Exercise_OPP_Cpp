#ifndef CERTIFICATE_HPP
#define CERTIFICATE_HPP
#include <string>
#include <iostream>

class Certificate {
private:
    std::string certificateID;
    std::string certificateName;
    std::string certificateRank;
    std::string certificateDate;

public:
    Certificate(const std::string& id, const std::string& name, const std::string& rank, const std::string& date);
    ~Certificate();

    std::string getCertificateID() const;
    void setCertificateID(const std::string& id);

    std::string getCertificateName() const;
    void setCertificateName(const std::string& name);

    std::string getCertificateRank() const;
    void setCertificateRank(const std::string& rank);

    std::string getCertificateDate() const;
    void setCertificateDate(const std::string& date);

    void showCertificateInfo() const;
};

#endif // CERTIFICATE_HPP