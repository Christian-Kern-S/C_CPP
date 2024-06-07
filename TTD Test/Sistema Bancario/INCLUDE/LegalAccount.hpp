#ifndef LEGAL_ACCOUNT_HPP
#define LEGAL_ACCOUNT_HPP
#include "IAccount.hpp"

class LegalAccount : public IAccount 
{
public:
    LegalAccount(AccountType type)
    {
        setName("Legal Account");
        registrationStatus_ = "Active";
        type_ = type;
    }
    std::string getRegistrationStatus() { return registrationStatus_; }
    std::string getOpeningDate() { return openingDate_; }
    inline std::string getName() const override { return name_; }
    inline std::string getDocument() const override { return document_; }
    inline AccountType getType() const override { return type_; }
    inline double getBalance() const override { return balance_; }
    inline bool isPremium() const override { return false; }

    void setName(std::string name) override;
    void setBalance (int balance) override;
    bool setDocument(std::string document) override;
    void setRegistrationStatus(std::string status);
    void setOpeningDate(std::string date);
    bool verifyDocument(const std::string& document) override;

private:
    std::string registrationStatus_{"Inactive"};
    std::string openingDate_{"00/00/0000"};
};
#endif