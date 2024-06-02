#include "../INCLUDE/Bank.hpp"

IAccount* Bank::create(AccountType type)
{
    switch (type)
    {
    case AccountType::PHYSICAL:{
        return new PhysicalAccount(AccountType::PHYSICAL);
        break;
    }

    case AccountType::PREMIUM_PHYSICAL:{
        PhysicalAccount* physical = new PhysicalAccount(AccountType::PHYSICAL);
        return new PremiumPhysicalAccount(physical);
        break;
    }

    case AccountType::LEGAL:{
        return new LegalAccount(AccountType::LEGAL);
        break;
    }

    case AccountType::PREMIUM_LEGAL:{
        LegalAccount* legal = new LegalAccount(AccountType::LEGAL);
        return new PremiumPhysicalAccount(legal);
        break;
    }
    
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