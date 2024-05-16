#ifndef I_PHYSICAL_ACCOUNT_HPP
#define I_PHYSICAL_ACCOUNT_HPP

#include <string>

class IPhysicalAccount
{
public:
    virtual ~IPhysicalAccount(){};
    virtual std::string getCpf() const = 0;
    virtual void setCpf(std::string cpf) = 0;
};
#endif