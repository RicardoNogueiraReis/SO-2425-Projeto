#pragma once

#include "../Entities/cidadao.h"
#include "../Entities/supermercado.h"

#define PATH_FILENAME_SIZE 31

typedef struct fileTestData FileTestData;
typedef FileTestData *pt_FileTestData;

typedef struct fileTestData {
    int TotalAvenidas;
    int TotalRuas;

    int NumeroCidadaos;
    int NumeroSupermercados;

    pt_Cidadao *Cidadaos;
    pt_supermercado *Supermercados;
} FileTestData;

pt_FileTestData readFileData(const char* fileName);

void freeData(pt_FileTestData data);

void freeEveryEntity(pt_FileTestData data);