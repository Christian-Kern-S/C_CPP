#ifndef LEGAL_ACCOUNT_HPP
#define LEGAL_ACCOUNT_HPP
#include "IAccount.hpp"

class LegalAccount : public IAccount 
{
public:
    LegalAccount(AccountType type)
    {
        setName("Legal Account");
        _registrationStatus = "Active";
        type_ = type;
    }
    std::string getRegistrationStatus() { return _registrationStatus; }
    std::string getOpeningDate() { return _openingDate; }
    inline std::string getName() const override { return name_; }
    inline std::string getDocument() const override { return document_; }
    inline AccountType getType() const override { return type_; }
    inline double getBalance() const override { return balance_; }

    void setName(std::string name) override;
    void setBalance (int balance) override;
    void setDocument(std::string document) override;
    void setRegistrationStatus(bool status);
    void setOpeningDate(std::string day, std::string month, std::string year);
    bool verifyDocument(const std::string& document) override;

private:
    std::string _registrationStatus{"Inactive"};
    std::string _openingDate{"00/00/0000"};
};
#endif