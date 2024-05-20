#include "../INCLUDE/Account.hpp"

void Account::setName(std::string name)
{
    _name = name;
}

void Account::setBalance(int balance)
{
    _balance = balance;
}

void Account::setDocument(std::string document)
{
    _document = document;
}

bool Account::verifyCpf(const std::string& document)
{
    if(document.size() != 11 || static_cast<std::string::size_type>(std::count(document.begin(), document.end(), document[0])) == document.size())
    {
        return false;
    }

    int total = 0;
    int remainder = 0;

    for(int i = 0; i < 9; ++i)
    {
        total += (document[i] - '0') * (10 - i);
    }
    remainder = total % 11;
    if(remainder < 2) remainder = 0;
    else remainder = 11 - remainder;

    if(remainder != (document[9] - '0'))
    {
        return false;
    }
    total = 0;
    remainder = 0;

    for(int i = 0; i < 10; ++i)
    {
        total += (document[i] - '0') * (11 - i);
    }
    remainder = total % 11;
    if(remainder < 2) remainder = 0;
    else remainder = 11 - remainder;

    return remainder == (document[10] - '0');
}
bool Account::verifyCnpj(const std::string& document)
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