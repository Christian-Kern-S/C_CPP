#include "../INCLUDE/Bank.hpp"

IAccount* Bank::create(AccountType type)
{
    switch (type)
    {
    case AccountType::PHYSICAL:
        return new PhysicalAccount(AccountType::PHYSICAL);
        break;

    case AccountType::LEGAL:
        return new LegalAccount(AccountType::LEGAL);
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