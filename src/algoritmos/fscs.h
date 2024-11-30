#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../adts/esquina.h"
#include "../Entities/cidadao.h"
#include "../Entities/supermercado.h"
#include "../utils/data.h"
#include "../adts/mapaEsquina.h"

int calculateMaxSolutions(const int numCidadaos, const int numSupermercados);

// int findSafeCitizen(int* numSolucoes, pt_Esquina **mapa, pt_FileTestData data);

int findSafeCitizen(int citizenID, PtMapaEsquina mapa, pt_FileTestData data);

void vizinho_init(pt_Esquina vizinho, const int avenidaAtual, const int ruaAtual, pt_Esquina **mapa, pt_FileTestData data, int direcao);

/*pt_Esquina* vizinhos_init(const int avenida, const int rua, pt_Esquina **mapa, pt_FileTestData data);*/