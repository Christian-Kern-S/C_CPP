#include "../INCLUDE/PremiumLegalAccount.hpp"

void PremiumLegalAccount::setName(std::string name)
{
    name_ = name;
}

void PremiumLegalAccount::setBalance(int balance)
{
    balance_ = balance;
}

bool PremiumLegalAccount::setDocument(std::string document)
{
    if(verifyDocument(document) == true)
    {
        document_ = document;
        return true;
    }
    return false;
}

void PremiumLegalAccount::setOpeningDate(std::string day, std::string month, std::string year)
{
    std::string date = day + "/" + month + "/" + year;
    openingDate_ = date;
}

void PremiumLegalAccount::setRegistrationStatus(bool status)
{   
    if (status == 1)
    {
        registrationStatus_ = "Active";
    }
    else if (status == 0)
    {
        registrationStatus_ = "Inactive";
    }
}

bool PremiumLegalAccount::verifyDocument(const std::string& document)
{
        static const int multipliers1[] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
        static const int multipliers2[] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

        if (document.length() != 14)
        {
            return false;
        }
        int soma = 0;
        for (int i = 0; i < 12; i++)
        {
            soma += (document[i] - '0') * multipliers1[i];
        }
        int remainder = soma % 11;
        if (remainder < 2 && document[12] != '0')
        {
            return false;
        }
        if (remainder >= 2 && document[12] != (11 - remainder) + '0')
        {
            return false;
        }
        soma = 0;
        for (int i = 0; i < 13; i++)
        {
            soma += (document[i] - '0') * multipliers2[i];
        }
        remainder = soma % 11;
        if (remainder < 2 && document[13] != '0')
        {
            return false;
        }
        if (remainder >= 2 && document[13] != (11 - remainder) + '0')
        {
            return false;
        }
        return true;
}