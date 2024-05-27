#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "IAccount.hpp"
#include <map>

class Observer
{
public:
    virtual void update(int _accounts) = 0;
};
#endif