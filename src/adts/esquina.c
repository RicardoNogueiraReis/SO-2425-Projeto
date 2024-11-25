#include <stdio.h>
#include <stdlib.h>

#include "esquina.h"

pt_Esquina esquina_init(const int avenida, const int rua) {

    pt_Esquina newEsquina = malloc(sizeof(Esquina));

    if (!newEsquina)
    {
        puts("ERRO: Falha ao alocar memória para a esquina.");
        exit(EXIT_FAILURE);
    }

    newEsquina->Avenida = avenida;
    newEsquina->Rua = rua;

    newEsquina->FoiVisitado = false;

    return newEsquina;
}

pt_Esquina** mapa_init(const int avenidas, const int ruas) {
    pt_Esquina **newMapa = malloc(avenidas * sizeof(pt_Esquina *));

    for (int i = 0; i < avenidas; i++) {
        newMapa[i] = malloc(ruas * sizeof(pt_Esquina));

        for (int j = 0; j < ruas; j++) {
            newMapa[i][j] = esquina_init(i, j);

        }
    }

    return newMapa;
}

void print_esquina(pt_Esquina esquina, const int avenidas, const int ruas) {
    if(esquina == NULL) {
        printf("NULL ");
        return;
    }

    printf("[%d][%d] ", esquina->Avenida, esquina->Rua);
}

void print_mapa(pt_Esquina **mapa, const int avenidas, const int ruas) {

    for (int i = 0; i < avenidas; i++) {

        for (int j = 0; j < ruas; j++) {
            if(mapa[i][j] == NULL) {
                printf("NULL ");
                continue;
            }

            printf("[%d][%d] ", i, j);

        }

        puts("");
    }

}

void freeMapa(pt_Esquina **mapa, const int avenidas, const int ruas) {
    for (int i = 0; i < avenidas; i++)
    {
        for (int j = 0; j < ruas; j++)
        {
            free(mapa[i][j]);
        }

        free(mapa[i]);
    }

    free(mapa);

}
