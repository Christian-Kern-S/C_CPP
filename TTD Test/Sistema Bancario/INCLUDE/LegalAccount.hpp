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
        setCnpj("0");
    }
    std::string getRegistrationStatus() { return _registrationStatus; }
    std::string getOpeningDate() { return _openingDate; }
    std::string getCnpj() { return _cnpj; }
    
    void setRegistrationStatus(bool status);
    void setOpeningDate(std::string day, std::string month, std::string year);
    void setCnpj(std::string cnpj);

private:
    std::string _cnpj{"0"};
    std::string _registrationStatus{"Inactive"};
    std::string _openingDate{"00/00/0000"};
};
#endif