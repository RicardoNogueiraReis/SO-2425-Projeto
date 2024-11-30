#pragma once

typedef struct supermercado {
    int id;
    int avenida;
    int rua;
    // Lista de vertex
    
} Supermercado;

typedef Supermercado *pt_supermercado;

void supermercado_init(pt_supermercado novoSupermercado, const int id, const int avenida, const int rua);

void supermercado_getId(pt_supermercado supermercado, int *id);

void supermercado_getAvenida(pt_supermercado supermercado, int *avenida);

void supermercado_getRua(pt_supermercado supermercado, int *rua);