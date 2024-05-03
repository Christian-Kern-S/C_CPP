#include "../INCLUDE/Bank.hpp"

IAccount* Bank::create(AccountType t)
{
    switch (t)
    {
    case AccountType::PHYSICAL:
        return new PhysicalAccount();
        break;

    case AccountType::LEGAL:
        return new LegalAccount();
        break;

    default:
        return new NullAccount();
        break;
    }
}

Bank& Bank::getInstance()
{
    static Bank instance;
    return instance;
}