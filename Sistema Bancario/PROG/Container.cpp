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

void Container::addAccount(AccountType type)
{   
    _accounts[i] = bank.create(type);
    i++;
}

double Container::getBalanceById(int id)
{
    if (_accounts.find(setID(id)) != _accounts.end())
    {
        return _accounts[id]->getBalance();
    }
    return -1;
}