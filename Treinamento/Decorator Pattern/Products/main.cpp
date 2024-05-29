#include "T_Shirt.hpp"
#include "Decorator.hpp"
#include "StampDecorator.hpp"
#include "Customization.hpp"
#include <iostream>

T_Shirt* tshirt = new T_Shirt();
StampDecorator* tshirtWithStampFront = new StampDecorator(tshirt);
Customization* customizedTshirt = new Customization(tshirt);

void print_tshirt(){
    std::cout << tshirt->getPrice() << " - " << tshirt->getName() << std::endl;
    std::cout << tshirtWithStampFront->getPrice() << " - " << tshirtWithStampFront->getName() << std::endl;
    std::cout << customizedTshirt->getPrice() << " - " << customizedTshirt->getName() << std::endl;
}

int main(){
    print_tshirt();
    return 0;
}
