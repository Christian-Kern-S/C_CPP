#ifndef DEPOSIT_HPP
#define DEPOSIT_HPP

#include "Container.hpp"
#include <iostream>

class Deposit
{
public:
    Deposit(Container& container) : container_(container)
    {
    }
    bool deposit(int id,double value);

private:
    Container& container_;
};
#endif