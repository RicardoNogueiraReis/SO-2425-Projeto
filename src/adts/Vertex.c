#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Vertex.h"


pt_Vertex vertex_init(const int avenida, const int rua) {
    
    pt_Vertex newVertex; // TODO: fazer a alocação de memória
    newVertex.Avenida = avenida;
    newVertex.Rua = rua;

    newVertex.FoiVisitado = false;

    return newVertex;
}
