#ifndef LEGAL_ACCOUNT_HPP
#define LEGAL_ACCOUNT_HPP
#include "Account.hpp"

class LegalAccount : public Account 
{
public:
    LegalAccount() : Account(AccountType::LEGAL)
    {
        setName("Legal Account");
        _registrationStatus = "Active";
    }
    std::string getRegistrationStatus() { return _registrationStatus; }
    std::string getOpeningDate() { return _openingDate; }
    
    void setRegistrationStatus(bool status);
    void setOpeningDate(std::string day, std::string month, std::string year);

private:
    std::string _registrationStatus{"Inactive"};
    std::string _openingDate{"00/00/0000"};
};
#endif