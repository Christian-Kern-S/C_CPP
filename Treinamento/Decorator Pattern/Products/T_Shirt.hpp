#include "IProduct.hpp"

class T_Shirt : public IProduct
{
public:
    std::string getName() override { return name_; }
    double getPrice() override { return number_; }

private:
    double number_ = 49.90;
    std::string name_ = "Camiseta";
};