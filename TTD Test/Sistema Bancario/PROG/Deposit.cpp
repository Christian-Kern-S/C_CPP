#include "../INCLUDE/Deposit.hpp"

bool Deposit::deposit(int id, double value)
{
    if (_container.getAccount().find(id) != _container.getAccount().end())
    {
        _container.getAccountById(id)->setBalance(value);
        return 1;
    }
    return 0;
}