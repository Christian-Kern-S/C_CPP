#include "../INCLUDE/Draft.hpp"

bool Draft::withdraw(int id, double value)
{
    if(_container.getAccountById(id)->getBalance() >= value)
    {
        _container.getAccountById(id)->setBalance(_container.getAccountById(id)->getBalance() - value);
        return true;
    }
    return false;
}