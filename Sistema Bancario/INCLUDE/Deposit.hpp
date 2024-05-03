#ifndef DEPOSIT_HPP
#define DEPOSIT_HPP

#include "Container.hpp"
#include <iostream>

class Deposit
{
public:
    Deposit(Container& container) : _container(container)
    {
    }
    void deposit(int id,double value);

private:
    Container& _container;
};
#endif