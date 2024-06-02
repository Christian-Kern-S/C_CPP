#ifndef PREMIUM_PHYSICAL_ACCOUNT_HPP
#define PREMIUM_PHYSICAL_ACCOUNT_HPP

#include "IAccount.hpp"

class PremiumPhysicalAccount : public IAccount
{
public:
    PremiumPhysicalAccount(IAccount* account) : premiumPhysicalAccount_(account)
    {
        setName("Premium Physical Account");
    }
    inline std::string getName() const override { return name_; }
    inline std::string getDocument() const override { return document_; }
    inline AccountType getType() const override { return type_; }
    inline double getBalance() const override { return balance_; }
    inline bool isPremium() const override { return true; }

    void setName(std::string name) override;
    void setBalance (int balance) override;
    bool setDocument(std::string document) override;
    bool verifyDocument(const std::string& document) override;

private:
    IAccount* premiumPhysicalAccount_;
};
#endif