#ifndef NULL_PHYSICAL_ACCOUNT_HPP
#define NULL_PHYSICAL_ACCOUNT_HPP

#include "IPhysicalAccount.hpp"

class NullPhysicalAccount : public IPhysicalAccount
{
public:
    std::string getCpf() const override { return ""; };
    void setCpf(std::string cpf) override {};
};
#endif