#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <map>
#include <iostream>
//#include "IAccount.hpp"
#include "Bank.hpp"
#include "LegalAccount.hpp"
#include "PhysicalAccount.hpp"
#include "NullPhysicalAccount.hpp"

class Container
{
public:
    AccountType getTypeById(int id) { return (_accounts.find(id) != _accounts.end()) ? _accounts[id]->getType() : AccountType::INVALID; }
    IAccount* getAccountById(int id) { return (_accounts.find(id) != _accounts.end()) ? _accounts[id] : 0; }

    double getBalanceById(int id) { return (_accounts.find(id) != _accounts.end()) ? _accounts[id]->getBalance() : false;}
    std::string getCnpjById(int id) { return (_accounts.find(id) != _accounts.end() && _accounts[id]->getType() == AccountType::LEGAL) ? LegalDynamicCast(id)->getCnpj() : "false"; }
    std::string getCpfById(int id) { return (_accounts.find(id) != _accounts.end() && _accounts[id]->getType() == AccountType::PHYSICAL) ? PhysicalDynamicCast(id)->getCpf() : "false"; }

    std::string getNameById(int id) { return (_accounts.find(id) != _accounts.end()) ? _accounts[id]->getName() : "Invalid"; }
    std::string getRegistrationStatusById(int id) { return (_accounts.find(id) != _accounts.end() && _accounts[id]->getType() == AccountType::LEGAL) ? LegalDynamicCast(id)->getRegistrationStatus() : "Invalid"; }
    std::string getOpeningDateById(int id) { return (_accounts.find(id) != _accounts.end() && _accounts[id]->getType() == AccountType::LEGAL) ? LegalDynamicCast(id)->getOpeningDate() : "Invalid"; }

    bool addAccount(AccountType type);
    bool deleteAccount(int id);

    std::map<int,IAccount*> getAccount(){ return _accounts; }

protected:
    std::map<int,IAccount*> _accounts;

    bool setAccountName(int id, std::string name);
    bool setAccountCpf(int id, std::string);
    bool setAccountCnpj(int id, std::string cnpj);
    bool setAccountRegistrationStatus(int id, double status);
    bool setAccountOpeningDate(int id, std::string day, std::string month, std::string year);

    LegalAccount* LegalDynamicCast(int id);
    IPhysicalAccount* PhysicalDynamicCast(int id);

private:
    Bank& bank = Bank::getInstance();
    int i{1};
};
#endif