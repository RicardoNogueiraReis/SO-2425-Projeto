#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../adts/esquina.h"
#include "../Entities/cidadao.h"
#include "../Entities/supermercado.h"
#include "../utils/data.h"
#include "../adts/mapaEsquina.h"
#include "../adts/PathList.h"

int calculateMaxSolutions(const int numCidadaos, const int numSupermercados);

int findSafeCitizen(int citizenID, PtMapaEsquina mapa, pt_FileTestData data, PtPathList pathList);