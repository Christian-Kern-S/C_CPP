#ifndef CARRO_H
#define CARRO_H

#include <iostream>

class Carro
{

public:
    virtual void iniciar(void) = 0;
    static Carro *factory(int);
};

class GM : public Carro
{
public:
    void iniciar(void) { std::cout << "Ola sou GM" << std::endl; }
};

class Ford : public Carro
{
public:
    void iniciar(void) { std::cout << "Ola sou GM" << std::endl; }
};

class Volkswagen : public Carro
{
public:
    void iniciar(void) { std::cout << "Ola sou GM" << std::endl; }
};

#endif // CARRO_H