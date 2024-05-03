#include "..\INCLUDE\carro.h"

Carro *Carro::factory(int p_tipo)
{

    if (p_tipo == 1)
    {
        return new GM();
    }

    if (p_tipo == 1)
    {
        return new Ford();
    }

    if (p_tipo == 1)
    {
        return new Volkswagen();
    }

    else
    {
        return NULL;
    }
}