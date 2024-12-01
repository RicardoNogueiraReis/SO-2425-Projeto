#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "esquina.h"

void esquina_init(pt_Esquina esquina, const int avenida, const int rua) {
    if (esquina == NULL)
        return;
    
    esquina->Avenida = avenida;
    esquina->Rua = rua;

    esquina->FoiVisitado = false;
}

void esquina_getAvenida(pt_Esquina esquina, int *avenida) {
    if (esquina == NULL)
        return;
    
    *avenida = esquina->Avenida;
}

void esquina_getRua(pt_Esquina esquina, int *rua) {
    if (esquina == NULL)
        return;
    
    *rua = esquina->Rua;
}

void esquina_Visit(pt_Esquina esquina) {
    if (esquina == NULL)
        return;

    esquina->FoiVisitado = true;
}

bool esquina_WasVisited(pt_Esquina esquina) {
    if (esquina == NULL)
        return false;

    return esquina->FoiVisitado;
}

void print_esquina(pt_Esquina esquina) {
    if(esquina == NULL)
        return;

    printf("[%d][%d]", esquina->Avenida, esquina->Rua);
}