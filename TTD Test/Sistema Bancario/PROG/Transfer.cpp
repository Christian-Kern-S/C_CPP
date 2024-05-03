#include "../INCLUDE/Transfer.hpp"

bool Transfer::transfer(int id1, double value, int id2)
{
    if(_container.getAccountByID(id1)->getBalance() >= value)
    {
        _container.getAccountByID(id1)->setBalance(_container.getAccountByID(id1)->getBalance() - value);
        _container.getAccountByID(id2)->setBalance(_container.getAccountByID(id2)->getBalance() + value);
        return 1;
    }
    return 0;
}