#include "../INCLUDE/Transfer.hpp"

bool Transfer::transfer(int id1, double value, int id2)
{
    auto finder1 = container_.getAccount().find(id1);
    auto finder2 = container_.getAccount().find(id2);
    auto end = container_.getAccount().end();
    if (finder1 != end && finder2 != end)
    {
        if(container_.getBalanceById(id1) >= value)
        {
            container_.getAccountById(id1)->setBalance(container_.getAccountById(id1)->getBalance() - value);
            container_.getAccountById(id2)->setBalance(container_.getAccountById(id2)->getBalance() + value);
            return true;
        }
        return false;
    }
     return false;
}