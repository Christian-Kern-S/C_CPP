#ifndef I_PRODUCT
#define I_PRODUCT

#include <string>

class IProduct
{
public:
    virtual double getPrice() = 0;
    virtual std::string getName() = 0;
};

#endif