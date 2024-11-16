#include <stdio.h>
#include <stdlib.h>

#include "supermercado.h"



pt_supermercado supermercado_init(const int id, const int avenida, const int rua) {

    pt_supermercado newSupermercado = malloc(sizeof(Supermercado));

    if (!newSupermercado) {
        puts("ERRO: Falha ao alocar memória para o cidadão.");
        exit(EXIT_FAILURE);
    }

    newSupermercado->id = id;
    newSupermercado->avenida = avenida;
    newSupermercado->rua = rua;

    return newSupermercado;

}