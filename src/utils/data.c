#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "../Entities/cidadao.h"
#include "../Entities/supermercado.h"

void readEntityFromFile(pt_FileTestData data, FILE *file, char entity);

void readFileData(pt_FileTestData data, const char* fileName) {

    char fileDirectory[PATH_FILENAME_SIZE] = "../file_tests/";
    strcat(fileDirectory, fileName);

    FILE *file = fopen(fileDirectory, "r");
    if (!file) {
        printf("ERRO: Ficheiro \"%s\" não existe.\n", fileName);

        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", &data->TotalAvenidas, &data->TotalRuas);
    fscanf(file, "%d %d", &data->NumeroSupermercados, &data->NumeroCidadaos);

    readEntityFromFile(data, file, 's');
    readEntityFromFile(data, file, 'c');

    fclose(file);

}

void readEntityFromFile(pt_FileTestData data, FILE *file, const char entity) {

    int count = 0;

    switch (entity)
    {
        case 'c': case 'C':
            count = data->NumeroCidadaos;
            break;
        
        case 's': case 'S':
            count = data->NumeroSupermercados;
            break;
        
        default:
            exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        int avenida = -1, rua = -1;

        switch (entity) {
            case 'c': case 'C':
                fscanf(file, "%d %d", &avenida, &rua);
                cidadao_init(&data->Cidadaos[i], i + 1, avenida, rua);
                break;
            
            case 's': case 'S':
                fscanf(file, "%d %d", &avenida, &rua);
                supermercado_init(&data->Supermercados[i], i + 1, avenida, rua);
                break;

        }
    }
    
}


int data_getTotalAvenidas(pt_FileTestData data) {
    return data->TotalAvenidas;
}

int data_getTotalRuas(pt_FileTestData data) {
    return data->TotalRuas;
}

int data_getNumeroCidadaos(pt_FileTestData data) {
    return data->NumeroCidadaos;
}

int data_getNumeroSupermercados(pt_FileTestData data) {
    return data->NumeroSupermercados;
}

pt_Cidadao data_getCidadao(pt_FileTestData data, int i) {
    return &data->Cidadaos[i];
}

pt_supermercado data_getSupermercado(pt_FileTestData data, int i) {
    return &data->Supermercados[i];
}