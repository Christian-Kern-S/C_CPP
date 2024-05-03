#ifndef ADDITION_HPP
#define ADDITION_HPP

#include "Calculator.hpp"

class Addition : public Calculator
{
public:
    Addition()
    {
        setName("Addition");
    }
    float sum(float number1, float number2);
};

#endif //ADDITION_HPP