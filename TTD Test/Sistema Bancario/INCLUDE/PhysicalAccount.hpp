#ifndef PHYSICAL_ACCOUNT_HPP
#define PHYSICAL_ACCOUNT_HPP

#include "IAccount.hpp"

class PhysicalAccount : public IAccount
{
public:
    PhysicalAccount(AccountType type)
    {
        type_ = type;
        setName("Physical Account");
    }
    inline std::string getName() const override { return name_; }
    inline std::string getDocument() const override { return document_; }
    inline AccountType getType() const override { return type_; }
    inline double getBalance() const override { return balance_; }

    void setName(std::string name) override;
    void setBalance (int balance) override;
    bool setDocument(std::string document) override;
    bool verifyDocument(const std::string& document) override;
};
#endif