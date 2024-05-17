#ifndef NULL_ACCOUNT_HPP
#define NULL_ACCOUNT_HPP

#include "IAccount.hpp"

class NullAccount : public IAccount
{
public:
    inline std::string getName() const override { return ""; }
    inline std::string getDocument() const override {return "";}
    inline AccountType getType() const override { return AccountType::INVALID; }
    inline double getBalance() const override { return false; }
    void setName(std::string name) override {};
    void setBalance (int balance) override {};
    void setDocument(std::string document)override {};
    bool verifyDocument(AccountType type, std::string document) override { return false; }
};
#endif