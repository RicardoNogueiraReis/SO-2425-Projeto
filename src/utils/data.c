#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "../Entities/cidadao.h"
#include "../Entities/supermercado.h"

void freeData(pt_FileTestData data);
void readEntityFromFile(pt_FileTestData data, FILE *file, char entity);

pt_FileTestData readFileData(const char* fileName) {

    pt_FileTestData data = malloc(sizeof(FileTestData));

    if (!data) {
        puts("ERRO: Falha ao alocar memória para os dados a receber.");
        exit(EXIT_FAILURE);
    }


    char fileDirectory[PATH_FILENAME_SIZE] = "../file_tests/";
    strcat(fileDirectory, fileName);

    FILE *file = fopen(fileDirectory, "r");
    if (!file) {
        printf("ERRO: Ficheiro \"%s\" não existe.\n", fileName);

        free(data);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", &data->TotalAvenidas, &data->TotalRuas);
    fscanf(file, "%d %d", &data->NumeroSupermercados, &data->NumeroCidadaos);


    
    data->Supermercados = malloc(data->NumeroSupermercados * sizeof(pt_supermercado));
    data->Cidadaos = malloc(data->NumeroCidadaos * sizeof(pt_Cidadao));

    if (!data->Supermercados || !data->Cidadaos) {
        if (!data->Supermercados)
            puts("ERRO: Falha ao alocar memória para listas de supermercados.");
        if (!data->Cidadaos)
            puts("ERRO: Falha ao alocar memória para listas de cidadãos.");

        fclose(file);
        freeData(data);
        exit(EXIT_FAILURE);
    }

    readEntityFromFile(data, file, 's');
    readEntityFromFile(data, file, 'c');

    fclose(file);

    return data;
}

void freeData(pt_FileTestData data) {
    free(data->Supermercados);
    free(data->Cidadaos);
    free(data);

}

void readEntityFromFile(pt_FileTestData data, FILE *file, char entity) {

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
                data->Cidadaos[i] = cidadao_init(i + 1, avenida, rua);
                break;
            
            case 's': case 'S':
                fscanf(file, "%d %d", &avenida, &rua);
                data->Supermercados[i] = supermercado_init(i + 1, avenida, rua);
                break;

        }
    }
    
}

void freeEveryEntity(pt_FileTestData data) {
    for (size_t i = 0; i < data->NumeroSupermercados; i++)
    {
        free(data->Supermercados[i]);
    }

    for (size_t i = 0; i < data->NumeroCidadaos; i++)
    {
        free(data->Cidadaos[i]);
    }

    freeData(data);
    
}