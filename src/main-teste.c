#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/mman.h>

#include "adts/esquina.h"
#include "adts/esquina.h"
#include "algoritmos/fscs.h"
#include "utils/data.h"
#include "utils/parameters.h"

#define ONE_MILISECOND 1000

#define ENABLE_PROCESS_TESTING 1

/**
 * @brief Main function
 *
 * @param argc Number of arguments provided
 * @param argv Array of arguments provided
 * @return int EXIT_SUCCESS when finished, else otherwise.
 */
int main(int argc, char **argv)
{
    // Depois do debug, estas variáveis devem ficar const
    const char *FILE_NAME = "instances_2.txt";
    const int NUMBER_OF_PROCESSES = 3;
    const int EXECUTION_TIME = 1000;

    argc = 4;

    printf("%s\n", FILE_NAME);
    printf("%i\n", NUMBER_OF_PROCESSES);
    printf("%i\n\n", EXECUTION_TIME);

    // Teste de inicialização
    ////////////////////////////////////////////

    pt_Esquina v = esquina_init(1, 2);

    printf("Vértice: Avenida %d, Rua %d, Foi Visitado: %s\n",
            v->Avenida,
            v->Rua,
            v->FoiVisitado ? "true" : "false");

    free(v);

    pt_Cidadao c = cidadao_init(1, 3, 2);

    printf("Cidadão ID: %d, Avenida: %d, Rua: %d\n",
            c->id,
            c->avenida,
            c->rua);

    free(c);

    // Teste de leitura de ficheiros
    ////////////////////////////////////////////

    pt_FileTestData data = readFileData(FILE_NAME);

    printf("Avenidas: %d, Ruas: %d\n", data->TotalAvenidas, data->TotalRuas);
    printf("Supermercados: %d, Cidadãos: %d\n", data->NumeroSupermercados, data->NumeroCidadaos);

    // Mapeamento das ESQUINAS
    ////////////////////////////////////////////

    pt_Esquina **mapa = mapa_init(data->TotalAvenidas, data->TotalRuas);

    // Representação visual
    ////////////////////////////////////////////

    for (size_t i = 0; i < data->TotalAvenidas; i++)
    {
        for (size_t j = 0; j < data->TotalRuas; j++)
        {
            printf("[%ld][%ld] ", i, j);
        }

        puts("");
    }

    freeMapa(mapa, data->TotalAvenidas, data->TotalRuas);

    // Teste de ouput dos dados
    ////////////////////////////////////////////

    puts("Cidadãos\n");
    for (size_t i = 0; i < data->NumeroCidadaos; i++)
    {
        printf("\tCidadãos: %d (%d,%d) \n",
                data->Cidadaos[i]->id,
                data->Cidadaos[i]->avenida,
                data->Cidadaos[i]->rua);
    }

    puts("Supermercados\n");
    for (size_t i = 0; i < data->NumeroSupermercados; i++)
    {
        printf("\tSupermercados: %d (%d,%d) \n",
                data->Supermercados[i]->id,
                data->Supermercados[i]->avenida,
                data->Supermercados[i]->rua);
    }

    // Libertação de memória
    ////////////////////////////////////////////
    
    freeEveryEntity(data);

    int pids[NUMBER_OF_PROCESSES];

    for(int i = 0; i < NUMBER_OF_PROCESSES; i++) {

        pids[i] = fork();

        if (pids[i] == 0) {

            while(1){
                printf("Worker process #%d!\n", i);

            }

        }
    }

    usleep(EXECUTION_TIME * ONE_MILISECOND);

    // Kill worker processes
    for (int i = 0; i < NUMBER_OF_PROCESSES; i++) {
        kill(pids[i], SIGKILL);

    }

    // */
    puts("Sucesso.");

    return EXIT_SUCCESS;
}
