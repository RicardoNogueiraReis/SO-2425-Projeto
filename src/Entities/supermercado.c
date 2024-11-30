#include <stdio.h>
#include <stdlib.h>

#include "supermercado.h"

void supermercado_init(pt_supermercado novoSupermercado, const int id, const int avenida, const int rua) {

    novoSupermercado->id = id;
    novoSupermercado->avenida = avenida;
    novoSupermercado->rua = rua;

}

void supermercado_getId(pt_supermercado supermercado, int *id) {
    if (supermercado == NULL)
        return;
    
    *id = supermercado->id;
    
}

void supermercado_getAvenida(pt_supermercado supermercado, int *avenida) {
    if (supermercado == NULL)
        return;
    
    *avenida = supermercado->avenida;

}

void supermercado_getRua(pt_supermercado supermercado, int *rua) {
    if (supermercado == NULL)
        return;
    
    *rua = supermercado->rua;

}