#include "../INCLUDE/Draft.hpp"

bool Draft::withdraw(int id, double value)
{
    auto finder = _container.getAccount().find(id);
    auto end = _container.getAccount().end();
    if (finder != end)
    {
        if(_container.getBalanceById(id) >= value)
        {
            _container.getAccountById(id)->setBalance(_container.getAccountById(id)->getBalance() - value);
            return true;
        }
        return false;
    }
    return false;
}