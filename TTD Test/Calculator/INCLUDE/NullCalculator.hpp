#ifndef NULLCALCULATOR_HPP
#define NULLCALCULATOR_HPP

#include "ICalculator.hpp"

class NullCalculator: public ICalculator
{
public:
    inline float getNumber1() const override { return 0; }
    inline float getNumber2() const override { return 0; }
    inline std::string getName() const override { return ""; }
    void reset() override {};
};

#endif //NULLCALCULATOR_HPP