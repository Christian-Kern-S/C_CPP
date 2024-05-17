#ifndef PHYSICAL_ACCOUNT_HPP
#define PHYSICAL_ACCOUNT_HPP

#include "Account.hpp"

class PhysicalAccount : public Account
{
public:
    PhysicalAccount() : Account (AccountType::PHYSICAL)
    {
        setName("Physical Account");
    }
};
#endif