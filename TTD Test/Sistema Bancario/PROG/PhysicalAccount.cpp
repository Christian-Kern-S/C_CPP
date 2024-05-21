#include "../INCLUDE/PhysicalAccount.hpp"


void PhysicalAccount::setName(std::string name)
{
    name_ = name;
}

void PhysicalAccount::setBalance(int balance)
{
    balance_ = balance;
}

void PhysicalAccount::setDocument(std::string document)
{
    if(verifyDocument(document) == true)
    {
        document_ = document;
    }
}

bool PhysicalAccount::verifyDocument(const std::string& document)
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