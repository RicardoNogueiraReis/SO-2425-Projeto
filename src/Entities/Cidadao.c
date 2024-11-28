#include <stdio.h>
#include <stdlib.h>

#include "cidadao.h"

typedef struct cidadao {
    int id;
    int avenida;
    int rua;
    // Lista de vertex
    
} Cidadao;


void cidadao_init(pt_Cidadao newCidadao, const int id, const int avenida, const int rua) {

    newCidadao->id = id;
    newCidadao->avenida = avenida;
    newCidadao->rua = rua;
}

void cidadao_getId(pt_Cidadao cidadao, int *id) {
    if (cidadao == NULL)
        return;
    
    *id = cidadao->id;
}

void cidadao_getAvenida(pt_Cidadao cidadao, int *avenida) {
    if (cidadao == NULL)
        return;
    
    *avenida = cidadao->avenida;
}

void cidadao_getRua(pt_Cidadao cidadao, int *rua) {
    if (cidadao == NULL)
        return;
    
    *rua = cidadao->rua;
}