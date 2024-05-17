#include "../INCLUDE/Transfer.hpp"

bool Transfer::transfer(int id1, double value, int id2)
{
    auto finder1 = _container.getAccount().find(id1);
    auto finder2 = _container.getAccount().find(id2);
    auto end = _container.getAccount().end();
    if (finder1 != end && finder2 != end)
    {
        if(_container.getBalanceById(id1) >= value)
        {
            _container.getAccountById(id1)->setBalance(_container.getAccountById(id1)->getBalance() - value);
            _container.getAccountById(id2)->setBalance(_container.getAccountById(id2)->getBalance() + value);
            return true;
        }
        return false;
    }
     return false;
}