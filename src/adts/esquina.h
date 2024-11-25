#pragma once

#include <stdbool.h>

typedef struct esquina Esquina;
typedef Esquina *pt_Esquina;

typedef struct esquina {
    int Avenida;        // A (1 a M) NORTE-SUL
    int Rua;            // B (1 a N) ESTE-OESTE.
    bool FoiVisitado;   // Por defeito, true (0)

} Esquina;

pt_Esquina esquina_init(const int avenida, const int rua);

void print_mapa(pt_Esquina **mapa, const int avenidas, const int ruas);

void print_esquina(pt_Esquina esquina, const int avenidas, const int ruas);

pt_Esquina** mapa_init(const int avenidas, const int ruas);

void freeMapa(pt_Esquina** mapa, const int avenida, const int rua);