#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "esquina.h"

typedef struct esquina {
    int Avenida;        // A (1 a M) NORTE-SUL.
    int Rua;            // B (1 a N) ESTE-OESTE.
    bool FoiVisitado;   // Por defeito, true (0)

} Esquina;

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

void print_esquina(pt_Esquina esquina) {
    if(esquina == NULL) {
        printf("NULL ");
        return;
    }

    printf("[%d][%d] ", esquina->Avenida, esquina->Rua);
}