#include "../INCLUDE/Container.hpp"

bool Container::addAccount(AccountType type)
{   
    if(type == AccountType::LEGAL || type == AccountType::PHYSICAL)
    {
        _accounts[i] = bank.create(type);
        i++;
        return true;
    }
    return false;
}

bool Container::deleteAccount(int id)
{
    auto toDelete = _accounts.find(id);
    if (toDelete != _accounts.end())
    {
        delete toDelete->second;
        _accounts.erase(toDelete);
        return true;
    }
    return false;
}

bool Container::setAccountName(int id, std::string name)
{
    if (_accounts.find(id) != _accounts.end())
    {
        _accounts[id]->setName(name);
        return true;
    }
    return false;
}

bool Container::setAccountDocument(int id, std::string document)
{
    if( _accounts.find(id) != _accounts.end() )
    {
        if(_accounts[id]->getType() == AccountType::LEGAL)
        {
            if(_accounts[id]->verifyDocument(_accounts[id]->getType(),document) == true)
            {
                _accounts[id]->setDocument(document);
                return true;
            }
            return false;
        }
        else if(_accounts[id]->getType() == AccountType::PHYSICAL)
        {
            if(_accounts[id]->verifyDocument(_accounts[id]->getType(), document) == true)
            {
                _accounts[id]->setDocument(document);
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}


bool Container::setAccountRegistrationStatus(int id, double status)
{
    if (_accounts.find(id) != _accounts.end() && _accounts[id]->getType() == AccountType::LEGAL)
    {
        LegalDynamicCast(id)->setRegistrationStatus(status);
        return true;
    }
    return false;
}
bool Container::setAccountOpeningDate(int id, std::string day, std::string month, std::string year)
{
    if (_accounts.find(id) != _accounts.end() && _accounts[id]->getType() == AccountType::LEGAL)
    {
        LegalDynamicCast(id)->setOpeningDate(day, month, year);
        return true;
    }
    return false;
}

LegalAccount* Container::LegalDynamicCast(int id)
{
        IAccount* account = _accounts[id];
        LegalAccount* legalAccount = dynamic_cast<LegalAccount*>(account);
        return legalAccount;
}