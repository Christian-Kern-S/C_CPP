#ifndef DRAFT_HPP
#define DRAFT_HPP

#include "Container.hpp"
#include "Deposit.hpp"

class Draft
{
public:
    Draft(Container& container) : _container(container)
    {
    }
    int withdraw(int id, double value);

private:
    Container& _container;
};
#endif