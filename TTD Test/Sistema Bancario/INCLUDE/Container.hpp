#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <map>
#include <iostream>
#include "IAccount.hpp"
#include "Bank.hpp"

class Container
{
public:
    AccountType getTypeById(int id);
    IAccount* getAccountById(int id);
    double getBalanceById(int id);
    
    bool addAccount(AccountType type);
    bool deleteAccount(int id);

    std::map<int,IAccount*> getAccount(){ return _accounts; }

protected:
    std::map<int,IAccount*> _accounts;

private:
    Bank& bank = Bank::getInstance();
    int i{1};
};
#endif