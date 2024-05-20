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
    inline std::string getDocument() const override { return _document; }
    inline AccountType getType() const override { return _type; }
    inline double getBalance() const override { return _balance; }
    void setName(std::string name) override;
    void setBalance (int balance) override;
    void setDocument(std::string document) override;
    bool verifyDocument(std::string document){
        switch (getType())
        {
        case AccountType::LEGAL:
            return verifyCnpj(document);
            break;
        case AccountType::PHYSICAL:
            return verifyCpf(document);
            break;

        default:
            return false;
            break;
        }
    }

protected:
    bool verifyCpf(const std::string& document);
    bool verifyCnpj(const std::string& document);

private:
    std::string _document{""};
    double _balance{0};
    std::string _name{""};
    AccountType _type{AccountType::INVALID};
};
#endif