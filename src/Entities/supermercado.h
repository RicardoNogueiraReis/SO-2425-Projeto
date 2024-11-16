#pragma once

typedef struct supermercado {
    int id;
    int avenida;
    int rua;
    // Lista de vertex
    
} Supermercado;

typedef Supermercado *pt_supermercado;

pt_supermercado supermercado_init(const int id, const int avenida, const int rua);