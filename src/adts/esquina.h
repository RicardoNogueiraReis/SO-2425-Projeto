#pragma once

typedef struct esquina {
    int Avenida;        // A (1 a M) NORTE-SUL.
    int Rua;            // B (1 a N) ESTE-OESTE.
    bool FoiVisitado;   // Por defeito, true (0)

} Esquina;

typedef Esquina *pt_Esquina;

void esquina_init(pt_Esquina esquina, const int avenida, const int rua);

void esquina_getAvenida(pt_Esquina esquina, int *avenida);

void esquina_getRua(pt_Esquina esquina, int *rua);

void esquina_Visit(pt_Esquina esquina);

bool esquina_WasVisited(pt_Esquina esquina);

void print_esquina(pt_Esquina esquina);