#include "../INCLUDE/Container.hpp"

IAccount* Container::getAccountById(int id)
{
    if (_accounts.find(id) != _accounts.end())
    {
        return _accounts[id];
    }
    return 0;
}

AccountType Container::getTypeById(int id)
{
    if (_accounts.find(id) != _accounts.end())
    {
        return _accounts[id]->getType();
    }
    return AccountType::INVALID;
}

bool Container::addAccount(AccountType type)
{   
    if(type == AccountType::LEGAL || type == AccountType::PHYSICAL)
    {
        _accounts[i] = bank.create(type);
        i++;
        return 1;
    }
    return 0;
}

double Container::getBalanceById(int id)
{
    if (_accounts.find(id) != _accounts.end())
    {
        return _accounts[id]->getBalance();
    }
    return 0;
}

bool Container::deleteAccount(int id)
{
    auto toDelete = _accounts.find(id);
    if (toDelete != _accounts.end())
    {
        delete toDelete->second;
        _accounts.erase(toDelete);
        return 1;
    }
    return 0;
}