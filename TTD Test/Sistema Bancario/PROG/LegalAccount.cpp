#include "../INCLUDE/LegalAccount.hpp"

void LegalAccount::setOpeningDate(std::string day, std::string month, std::string year)
{
    std::string date = day + "/" + month + "/" + year;
    _openingDate = date;
}

void LegalAccount::setRegistrationStatus(bool status)
{   
    if (status == 1)
    {
        _registrationStatus = "Active";
    }
    else if (status == 0)
    {
        _registrationStatus = "Inactive";
    }
}