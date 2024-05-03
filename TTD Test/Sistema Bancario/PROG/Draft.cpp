#include "../INCLUDE/Draft.hpp"

int Draft::withdraw(int id, double value)
{
    if(_container.getAccountByID(id)->getBalance() >= value)
    {
        _container.getAccountByID(id)->setBalance(_container.getAccountByID(id)->getBalance() - value);
        return 1;
    }
    else
    {
        return 0;
    }
}