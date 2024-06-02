#include "../INCLUDE/Container.hpp"

void Container::addObserver(Observer& observer)
{
    observers_.push_back(&observer);
}

bool Container::addAccount(AccountType type)
{   
    if(type == AccountType::LEGAL || type == AccountType::PHYSICAL || type == AccountType::PREMIUM_LEGAL || type == AccountType::PREMIUM_PHYSICAL)
    {
        _accounts[number_] = bank.create(type);
        number_++;
        notify();
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

void Container::notify()
{
    for(Observer* observer : observers_)
    {
        observer->update(number_);
    }
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
       return _accounts[id]->setDocument(document);
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