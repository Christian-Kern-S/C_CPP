#ifndef DRAFT_HPP
#define DRAFT_HPP

#include "Container.hpp"

class Draft
{
public:
    Draft(Container& container) : _container(container)
    {
    }
    bool withdraw(int id, double value);

private:
    Container& _container;
};
#endif