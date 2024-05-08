#include "../INCLUDE/Transfer.hpp"

bool Transfer::transfer(int id1, double value, int id2)
{
    if(_container.getAccountById(id1)->getBalance() >= value)
    {
        _container.getAccountById(id1)->setBalance(_container.getAccountById(id1)->getBalance() - value);
        _container.getAccountById(id2)->setBalance(_container.getAccountById(id2)->getBalance() + value);
        return 1;
    }
    return 0;
}