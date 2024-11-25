#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "fscs.h"

#define NORTE 0
#define ESTE 1
#define SUL 2
#define OESTE 3

int calculateMaxSolutions(const int numCidadaos, const int numSupermercados) {
    return (numCidadaos < numSupermercados) ? numCidadaos : numSupermercados;

}


int findSafeCitizen(int* numSolucoes, pt_Esquina **mapa, pt_FileTestData data) {

    // Localização atual
    int a = data->Cidadaos[0]->avenida; // A (1 a M) NORTE-SUL
    int b = data->Cidadaos[0]->rua; // B (1 a N) ESTE-OESTE.

    a = 0;
    b = 0;

    pt_Esquina* vizinhos = vizinhos_init(a, b, mapa, data);

    print_esquina(vizinhos[NORTE], data->TotalAvenidas, data->TotalRuas);
    print_esquina(vizinhos[ESTE], data->TotalAvenidas, data->TotalRuas);
    print_esquina(vizinhos[SUL], data->TotalAvenidas, data->TotalRuas);
    print_esquina(vizinhos[OESTE], data->TotalAvenidas, data->TotalRuas);

    return 0;
}

pt_Esquina* vizinhos_init(const int avenida, const int rua, pt_Esquina **mapa, pt_FileTestData data) {
    pt_Esquina* vizinhos = malloc(4 * sizeof(pt_Esquina));

    for (size_t i = 0; i < 4; i++) {

        switch (i) {
            case NORTE:
                if(avenida+1 > data->TotalAvenidas-1) {
                    vizinhos[NORTE] = NULL;
                    continue;
                }

                vizinhos[NORTE] = mapa[avenida+1][rua];
                break;

            case SUL:
                if(avenida-1 < 0) {
                    vizinhos[SUL] = NULL;
                    continue;
                }

                vizinhos[SUL] = mapa[avenida-2][rua];
                break;

            case ESTE:
                if(rua+1 > data->TotalRuas-1) {
                    vizinhos[ESTE] = NULL;
                    continue;
                }

                vizinhos[ESTE] = mapa[avenida][rua+1];
                break;

            case OESTE:
                if(rua-1 < 0) {
                    vizinhos[OESTE] = NULL;
                    continue;
                }

                vizinhos[OESTE] = mapa[avenida][rua-2];
                break;

        }

    }

    return vizinhos;
}

