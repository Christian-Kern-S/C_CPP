#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "IAccount.hpp"
#include <map>

class Observer
{
public:
    virtual void update(std::map<int,IAccount*> _accounts) = 0;
};
#endif