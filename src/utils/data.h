#pragma once

#include "../Entities/cidadao.h"
#include "../Entities/supermercado.h"

#define PATH_FILENAME_SIZE 31

typedef struct fileTestData FileTestData;
typedef FileTestData *pt_FileTestData;

void readFileData(pt_FileTestData data, const char* fileName);

int data_getTotalAvenidas(pt_FileTestData data);

int data_getTotalRuas(pt_FileTestData data);

int data_getNumeroCidadaos(pt_FileTestData data);

int data_getNumeroSupermercados(pt_FileTestData data);

pt_Cidadao data_getCidadao(pt_FileTestData data, int i);

pt_supermercado data_getSupermercado(pt_FileTestData data, int i);