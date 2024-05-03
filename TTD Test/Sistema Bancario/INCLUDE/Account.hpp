#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "IAccount.hpp"

class Account : public IAccount
{
public:
    Account(AccountType type)
    {
        _type = type;
    }

    inline std::string getName() const override { return _name; }
    inline AccountType getType() const override { return _type; }
    inline double getBalance() const override { return _balance; }


protected:
    void setName(std::string name) override;
    void setBalance (int balance) override;

private:
    double _balance{0};
    std::string _name{""};
    AccountType _type{AccountType::INVALID};
};
#endif