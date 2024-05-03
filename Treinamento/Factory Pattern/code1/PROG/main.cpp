#include <iostream>
#include "..\INCLUDE\carro.h"

int main()
{
    Carro *gm = Carro::factory(0);
    gm->iniciar();

    Carro *ford = Carro::factory(1);
    ford->iniciar();

    Carro *volkswagen = Carro::factory(3);
    volkswagen->iniciar();
}