#ifndef LEGAL_ACCOUNT_HPP
#define LEGAL_ACCOUNT_HPP
#include "Account.hpp"

class LegalAccount : public Account 
{
public:
    LegalAccount() : Account(AccountType::LEGAL)
    {
        setName("Legal Account");
    }
};
#endif