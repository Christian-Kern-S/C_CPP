#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <map>
#include <iostream>
#include "IAccount.hpp"
#include "Bank.hpp"


class Container
{
public:
    void addAccount(AccountType type);
    AccountType getTypeById(int id);
    IAccount* getAccountByID(int id);
    int setID(int id);
    double getBalanceById(int id);
    int getId() { return _id; }
    std::map<int,IAccount*> getAccount(){ return _accounts; }

protected:
    std::map<int,IAccount*> _accounts;
    int _id{0};

private:
    Bank& bank = Bank::getInstance();
    int i{1};
};
#endif