#pragma once

typedef struct esquina Esquina;
typedef Esquina *pt_Esquina;

void esquina_init(pt_Esquina esquina, const int avenida, const int rua);

void esquina_getAvenida(pt_Esquina esquina, int *avenida);

void esquina_getRua(pt_Esquina esquina, int *rua);

void esquina_Visit(pt_Esquina esquina);

bool esquina_WasVisited(pt_Esquina esquina);

void print_esquina(pt_Esquina esquina);