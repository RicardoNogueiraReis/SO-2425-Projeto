#include <stdio.h>
#include <stdlib.h>

#include "Cidadao.h"

pt_Cidadao cidadao_init(const int id, const int avenida, const int rua) {

    pt_Cidadao newCidadao = malloc(sizeof(Cidadao));

    if (!newCidadao) {
        puts("ERRO: Falha ao alocar memória para o cidadão.");
        exit(EXIT_FAILURE);
    }

    newCidadao->id = id;
    newCidadao->avenida = avenida;
    newCidadao->rua = rua;

    return newCidadao;

}