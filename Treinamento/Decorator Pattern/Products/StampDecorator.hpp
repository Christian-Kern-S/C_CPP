#include "Decorator.hpp"

class StampDecorator : public Decorator
{
public:
    StampDecorator(IProduct* product) : Decorator(product), product_(product){}
    
    double getPrice() override { return product_->getPrice() + 10; }
    std::string getName() override { return product_->getName() + " Estampada"; }

protected:
    IProduct* product_;
};