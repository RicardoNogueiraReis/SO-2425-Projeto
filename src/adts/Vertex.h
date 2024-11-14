#include <stdbool.h>
#pragma once

typedef struct vertex Vertex;
typedef Vertex *pt_Vertex;

typedef struct vertex {
    int Avenida;        // A (1 a M) NORTE-SUL
    int Rua;            // B (1 a N) ESTE-OESTE.
    bool FoiVisitado;   // Por defeito, true (0)

} Vertex;

pt_Vertex vertex_init(const int avenida, const int rua);
