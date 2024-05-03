#ifndef TRANSFER_HPP
#define TRANSFER_HPP

#include "Container.hpp"

class Transfer
{
public:
    Transfer(Container& container) : _container(container)
    {
    }
    bool transfer(int id1, double value, int id2);

private:
    Container& _container;
};
#endif