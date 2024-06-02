#ifndef PREMIUM_LEGAL_ACCOUNT_HPP
#define PREMIUM_LEGAL_ACCOUNT_HPP

#include "IAccount.hpp"

class PremiumLegalAccount : public IAccount
{
public:
    PremiumLegalAccount(IAccount* account) : premiumLegalAccount_(account)
    {
        setName("Premium Account");
        registrationStatus_ = "Active";
    }
    std::string getRegistrationStatus() { return registrationStatus_; }
    std::string getOpeningDate() { return openingDate_; }
    inline std::string getName() const override { return name_; }
    inline std::string getDocument() const override { return document_; }
    inline AccountType getType() const override { return type_; }
    inline double getBalance() const override { return balance_; }
    inline bool isPremium() const override { return true; }

    void setName(std::string name) override;
    void setBalance (int balance) override;
    bool setDocument(std::string document) override;
    void setRegistrationStatus(bool status);
    void setOpeningDate(std::string day, std::string month, std::string year);
    bool verifyDocument(const std::string& document) override;

private:
    IAccount* premiumLegalAccount_;
    std::string registrationStatus_{"Inactive"};
    std::string openingDate_{"00/00/0000"};
};

#endif