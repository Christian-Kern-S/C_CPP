#ifndef I_ACCOUNT_HPP
#define I_ACCOUNT_HPP

#include <map>
#include <string>
#include <algorithm>

enum class AccountType
{
    INVALID = -1,
    PHYSICAL,
    PREMIUM_PHYSICAL,
    LEGAL,
    PREMIUM_LEGAL
};

class IAccount
{
public:
    virtual ~IAccount(){};
    virtual inline std::string getName() const = 0;
    virtual inline AccountType getType() const = 0;
    virtual inline double getBalance() const = 0;
    virtual inline std::string getDocument() const = 0;
    virtual inline bool isPremium() const = 0;
    virtual void setName(std::string name) = 0;
    virtual void setBalance(int balance) = 0;
    virtual bool setDocument(std::string document) = 0;
    virtual bool verifyDocument(const std::string& document) = 0;
    
protected:
    bool premium_{false};
    std::string document_{""};
    double balance_{0};
    std::string name_{""};
    AccountType type_{AccountType::INVALID};
};
#endif