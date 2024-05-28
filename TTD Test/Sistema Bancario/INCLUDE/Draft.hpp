#ifndef DRAFT_HPP
#define DRAFT_HPP

#include "Container.hpp"

class Draft
{
public:
    Draft(Container& container) : container_(container)
    {
    }
    bool withdraw(int id, double value);

private:
    Container& container_;
};
#endif