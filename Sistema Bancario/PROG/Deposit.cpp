#include "../INCLUDE/Deposit.hpp"

void Deposit::deposit(int id, double value)
{
    if (_container.getAccount().find(_container.setID(id)) != _container.getAccount().end())
    {
        _container.getAccountByID(id)->setBalance(value);
    }  
}