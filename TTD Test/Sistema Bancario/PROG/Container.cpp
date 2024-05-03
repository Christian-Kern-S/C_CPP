#include "../INCLUDE/Container.hpp"

IAccount* Container::getAccountByID(int id)
{
    if (_accounts.find(setID(id)) != _accounts.end())
    {
        return _accounts[id];
    }
    return 0;
}

int Container::setID(int id)
{
    _id = id;
    return _id;
}

AccountType Container::getTypeById(int id)
{
    if (_accounts.find(setID(id)) != _accounts.end())
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
    if (_accounts.find(setID(id)) != _accounts.end())
    {
        return _accounts[id]->getBalance();
    }
    return -1;
}