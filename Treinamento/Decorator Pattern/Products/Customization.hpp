#include "Decorator.hpp"

class Customization : public Decorator
{
public:
    Customization(IProduct* product) : Decorator(product), product_(product){}
    
    double getPrice() override { return product_->getPrice() + 50; }
    std::string getName() override { return product_->getName() + " Customizada"; }

protected:
    IProduct* product_;
};