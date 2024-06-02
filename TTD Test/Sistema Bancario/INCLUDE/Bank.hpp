#ifndef BANK_HPP
#define BANK_HPP

#include "NullAccount.hpp"
#include "PhysicalAccount.hpp"
#include "LegalAccount.hpp"
#include "PremiumPhysicalAccount.hpp"

class Bank 
{
public:
    static Bank& getInstance();
    IAccount* create(AccountType t);
    
private:
    Bank(){}
};
#endif