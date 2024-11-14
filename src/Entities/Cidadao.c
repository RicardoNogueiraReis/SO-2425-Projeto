#include <stdio.h>
#include <stdlib.h>

#include "Cidadao.h"

pt_Cidadao cidadao_init(const int id, const int avenida, const int rua) {

    pt_Cidadao newCidadao; // TODO: fazer a alocação de memória
    newCidadao->id = id;
    newCidadao->avenida = avenida;
    newCidadao->rua = rua;

    return newCidadao;

}