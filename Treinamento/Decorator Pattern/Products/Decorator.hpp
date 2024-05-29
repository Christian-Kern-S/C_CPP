#ifndef DECORATOR
#define DECORATOR

#include "IProduct.hpp"

class Decorator : public IProduct
{
public:
    Decorator(IProduct* product) : product_(product){}

    std::string getName() override { return product_->getName(); }
    double getPrice() override { return product_->getPrice(); }

protected:
    IProduct* product_;    
};

#endif