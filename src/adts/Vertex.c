#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Vertex.h"


pt_Vertex vertex_init(const int avenida, const int rua) {
    
    pt_Vertex newVertex = malloc(sizeof(Vertex));

    if (!newVertex) {
        puts("ERRO: Falha ao alocar memória para o vértice.");
        exit(EXIT_FAILURE);
    }


    newVertex->Avenida = avenida;
    newVertex->Rua = rua;

    newVertex->FoiVisitado = false;

    return newVertex;
}
