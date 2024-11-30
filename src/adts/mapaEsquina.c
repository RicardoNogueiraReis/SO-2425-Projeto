#include <stdlib.h>
#include "mapaEsquina.h"
#include "Stack.h"

#define MAPA_SUCCESS 0
#define MAPA_IS_NULL 1
#define MAPA_INVALID_POSITION 2
#define MAPA_IS_EMPTY 3

int mapaCreate(PtMapaEsquina mapa, int avenidas, int ruas) {
    if (mapa == NULL)
        return MAPA_IS_NULL;

    mapa->maxAvenidas = avenidas;
    mapa->maxRuas = ruas;
    
    for (int i = 1; i <= avenidas; i++) {
        for (int j = 1; j <= ruas; j++) {
            mapa->mapa[i][j] = false;
        }
    }

    for(int i = 0; i < NUMBER_OF_SOLUCTIONS; i++) {
        stackCreate(&mapa->solucoes[i]);
    }

    return MAPA_SUCCESS;
}

int mapaIsEsquinaVisited(PtMapaEsquina mapa, int avenida, int rua, bool *esquinaStatus) {
    if (mapa == NULL)
        return MAPA_IS_NULL;

    if (avenida < 1 || avenida > mapa->maxAvenidas || rua < 1 || rua > mapa->maxRuas)
        return MAPA_INVALID_POSITION;    

    esquinaStatus = &mapa->mapa[avenida][rua];

    return MAPA_SUCCESS;
}

int mapaVisitEsquina(PtMapaEsquina mapa, int avenida, int rua) {
    if (mapa == NULL)
        return MAPA_IS_NULL;

    if (avenida < 1 || avenida > mapa->maxAvenidas || rua < 1 || rua > mapa->maxRuas)
        return MAPA_INVALID_POSITION;

    mapa->mapa[avenida][rua] = true;
    return MAPA_SUCCESS;
}

 










