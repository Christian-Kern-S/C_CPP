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

bool Container::setAccountCnpj(int id, std::string cnpj)
{
    if (_accounts.find(id) != _accounts.end())
    {
        if (LegalDynamicCast(id) == nullptr)
        {
            return false;
        }
        LegalDynamicCast(id)->setCnpj(cnpj);
        return true;
    }
    return false;
}

bool Container::setAccountCpf(int id, std::string cpf)
{
    if (_accounts.find(id) != _accounts.end())
    {
        if (PhysicalDynamicCast(id)->getCpf() == "")
        {
            return false;
        }
        PhysicalDynamicCast(id)->setCpf(cpf);
        return true;
    }
    return false;
}

bool Container::setAccountRegistrationStatus(int id, double status)
{
    if (_accounts.find(id) != _accounts.end())
    {
        LegalDynamicCast(id)->setRegistrationStatus(status);
        return true;
    }
    return false;
}
bool Container::setAccountOpeningDate(int id, std::string day, std::string month, std::string year)
{
    if (_accounts.find(id) != _accounts.end())
    {
        LegalDynamicCast(id)->setOpeningDate(day, month, year);
        return true;
    }
    return false;
}

LegalAccount* Container::LegalDynamicCast(int id)
{
    if (_accounts[id]->getType() == AccountType::LEGAL)
    {
        IAccount* account = _accounts[id];
        LegalAccount* legalAccount = dynamic_cast<LegalAccount*>(account);
        return legalAccount;
    }
    return nullptr;
}

IPhysicalAccount* Container::PhysicalDynamicCast(int id)
{
    
    if (_accounts[id]->getType() == AccountType::PHYSICAL)
    {
        IAccount* account = _accounts[id];
        PhysicalAccount* physicalAccount = dynamic_cast<PhysicalAccount*>(account);
        return physicalAccount;    
    }
    NullPhysicalAccount* nullPhysicalAccount = new NullPhysicalAccount();
    return nullPhysicalAccount;
}