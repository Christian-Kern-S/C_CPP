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
    inline std::map<int,IAccount*> getAccount() { return _accounts; }
    inline bool isAccountPremium(int id) { return (_accounts.find(id) != _accounts.end()) ? _accounts[id]->isPremium() : false; }
    
    void addObserver(Observer& observer);
    bool addAccount(AccountType type);
    bool deleteAccount(int id);
    bool upgradeAccount(int id);
    void notify();

protected:
    std::map<int,IAccount*> _accounts;

    bool setAccountName(int id, std::string name);
    bool setAccountDocument(int id, std::string document);
    bool setAccountRegistrationStatus(int id, std::string status);
    bool setAccountOpeningDate(int id, std::string date);

    LegalAccount* LegalDynamicCast(int id);
    int number_{1};

private:
    std::vector<Observer *> observers_;
    Bank& bank = Bank::getInstance();

    std::string TempDocument_{""};
    double TempBalance_{0};
    std::string TempName_{""}; 
    std::string TempRegistrationStatus_{"Inactive"};
    std::string TempOpeningDate_{"00/00/0000"};
};
#endif