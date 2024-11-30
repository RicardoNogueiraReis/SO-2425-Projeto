#pragma once

typedef struct cidadao {
    int id;
    int avenida;
    int rua;
    // Lista de vertex
    
} Cidadao;

typedef Cidadao *pt_Cidadao;

void cidadao_init(pt_Cidadao newCidadao, const int id, const int avenida, const int rua);

void cidadao_getId(pt_Cidadao cidadao, int *id);

void cidadao_getAvenida(pt_Cidadao cidadao, int *avenida);

void cidadao_getRua(pt_Cidadao cidadao, int *rua);