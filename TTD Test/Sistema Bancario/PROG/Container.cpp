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


bool Container::setAccountRegistrationStatus(int id, std::string status)
{
    if (_accounts.find(id) != _accounts.end() && _accounts[id]->getType() == AccountType::LEGAL)
    {
        LegalDynamicCast(id)->setRegistrationStatus(status);
        return true;
    }
    return false;
}
bool Container::setAccountOpeningDate(int id, std::string date)
{
    if (_accounts.find(id) != _accounts.end() && _accounts[id]->getType() == AccountType::LEGAL)
    {
        LegalDynamicCast(id)->setOpeningDate(date);
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

bool Container::upgradeAccount(int id)
{
    if (_accounts[id]->isPremium() == false)
    {
        auto toDelete = _accounts.find(id);
        if (toDelete != _accounts.end())
        {
            AccountType type = _accounts[id]->getType();
            switch (type)
            {
            case AccountType::PHYSICAL:{
                TempDocument_ = _accounts[id]->getDocument();
                TempBalance_ = _accounts[id]->getBalance();
                TempName_ = _accounts[id]->getName();

                delete toDelete->second;
                _accounts.erase(toDelete);
                _accounts[id] = bank.create(AccountType::PREMIUM_PHYSICAL);

                _accounts[id]->setDocument(TempDocument_);
                _accounts[id]->setBalance(TempBalance_);
                _accounts[id]->setName(TempName_);

                return true;
                break;
            }

            case AccountType::LEGAL:{
                TempDocument_ = _accounts[id]->getDocument();
                TempBalance_ = _accounts[id]->getBalance();
                TempName_ = _accounts[id]->getName();
                TempRegistrationStatus_ = getRegistrationStatusById(id);
                TempOpeningDate_ = getOpeningDateById(id);

                delete toDelete->second;
                _accounts.erase(toDelete);
                _accounts[id] = bank.create(AccountType::PREMIUM_LEGAL);

                _accounts[id]->setDocument(TempDocument_);
                _accounts[id]->setBalance(TempBalance_);
                _accounts[id]->setName(TempName_);
                setAccountRegistrationStatus(id, TempRegistrationStatus_);
                setAccountOpeningDate(id, TempOpeningDate_);

                return true;
                break;
            }

            default:
                return false;
                break;
            }
            return true;
        }
        return false;
    }
    return false;
}