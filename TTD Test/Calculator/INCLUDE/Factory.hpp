#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Calculator.hpp"
#include "Addition.hpp"
#include "Subtraction.hpp"
#include "Division.hpp"
#include "Multiplication.hpp"
#include "NullCalculator.hpp"

class Factory : public Calculator
{
public:
    static Factory& getInstance();
    ICalculator* create(CalculatorType t);
private:
    Factory(){}
};

#endif //FACTORY_HPP