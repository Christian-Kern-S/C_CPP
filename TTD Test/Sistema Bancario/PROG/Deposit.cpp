#include "../INCLUDE/Deposit.hpp"

bool Deposit::deposit(int id, double value)
{
    auto finder = container_.getAccount().find(id);
    auto end = container_.getAccount().end();
    if (finder != end)
    {
        container_.getAccountById(id)->setBalance(value);
        return true;
    }
    return false;
}