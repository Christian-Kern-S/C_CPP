#include "../INCLUDE/Deposit.hpp"

bool Deposit::deposit(int id, double value)
{
    if (_container.getAccount().find(_container.setID(id)) != _container.getAccount().end())
    {
        _container.getAccountByID(id)->setBalance(value);
        return 1;
    }
    return 0;
}