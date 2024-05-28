#ifndef TRANSFER_HPP
#define TRANSFER_HPP

#include "Container.hpp"

class Transfer
{
public:
    Transfer(Container& container) : container_(container)
    {
    }
    bool transfer(int id1, double value, int id2);

private:
    Container& container_;
};
#endif