#ifndef PHYSICAL_ACCOUNT_HPP
#define PHYSICAL_ACCOUNT_HPP

#include "IPhysicalAccount.hpp"
#include "Account.hpp"

class PhysicalAccount : public Account, public IPhysicalAccount
{
public:
    PhysicalAccount() : Account (AccountType::PHYSICAL)
    {
        setName("Physical Account");
        setCpf("0");
    }
    std::string getCpf() const override { return _cpf; }
    void setCpf(std::string cpf) override;

private:
    std::string _cpf{"0"};
};
#endif