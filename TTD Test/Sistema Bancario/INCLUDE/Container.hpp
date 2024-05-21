#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>
#include <map>
#include <iostream>
#include "Bank.hpp"
#include "LegalAccount.hpp"
#include "PhysicalAccount.hpp"
#include "Observer.hpp"


class Container
{
public:
    inline AccountType getTypeById(int id) { return (_accounts.find(id) != _accounts.end()) ? _accounts[id]->getType() : AccountType::INVALID; }
    inline IAccount* getAccountById(int id) { return (_accounts.find(id) != _accounts.end()) ? _accounts[id] : 0; }
    inline double getBalanceById(int id) { return (_accounts.find(id) != _accounts.end()) ? _accounts[id]->getBalance() : false;}
    inline std::string getDocumentById(int id) { return (_accounts.find(id) != _accounts.end()) ? _accounts[id]->getDocument() : "Invalid"; }
    inline std::string getNameById(int id) { return (_accounts.find(id) != _accounts.end()) ? _accounts[id]->getName() : "Invalid"; }
    inline std::string getRegistrationStatusById(int id) { return (_accounts.find(id) != _accounts.end() && _accounts[id]->getType() == AccountType::LEGAL) ? LegalDynamicCast(id)->getRegistrationStatus() : "Invalid"; }
    inline std::string getOpeningDateById(int id) { return (_accounts.find(id) != _accounts.end() && _accounts[id]->getType() == AccountType::LEGAL) ? LegalDynamicCast(id)->getOpeningDate() : "Invalid"; }
    inline std::map<int,IAccount*> getAccount(){ return _accounts; }
    
    void addObserver(Observer& observer);
    bool addAccount(AccountType type);
    bool deleteAccount(int id);
    void notify();

protected:
    std::map<int,IAccount*> _accounts;

    bool setAccountName(int id, std::string name);
    bool setAccountDocument(int id, std::string document);
    bool setAccountRegistrationStatus(int id, double status);
    bool setAccountOpeningDate(int id, std::string day, std::string month, std::string year);

    LegalAccount* LegalDynamicCast(int id);

private:
    std::vector<Observer *> observers_;
    Bank& bank = Bank::getInstance();
    int i_{1};
};
#endif