#include "../INCLUDE/Deposit.hpp"

bool Deposit::deposit(int id, double value)
{
    auto finder = _container.getAccount().find(id);
    auto end = _container.getAccount().end();
    if (finder != end)
    {
        _container.getAccountById(id)->setBalance(value);
        return true;
    }
    return false;
}