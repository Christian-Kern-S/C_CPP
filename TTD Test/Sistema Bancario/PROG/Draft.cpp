#include "../INCLUDE/Draft.hpp"

bool Draft::withdraw(int id, double value)
{
    auto finder = container_.getAccount().find(id);
    auto end = container_.getAccount().end();
    if (finder != end)
    {
        if(container_.getBalanceById(id) >= value)
        {
            container_.getAccountById(id)->setBalance(container_.getAccountById(id)->getBalance() - value);
            return true;
        }
        return false;
    }
    return false;
}