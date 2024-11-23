#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

#include "utils/Parameters.h"
#include "utils/data.h"
#include "adts/Vertex.h"
#include "Entities/Cidadao.h"

#define ENABLE_DEBUG 1



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
    char *FILE_NAME;
    int NUMBER_OF_PROCESSES;
    int EXECUTION_TIME;
    

    if(ENABLE_DEBUG){
        argc = 4;
        FILE_NAME = "instances_8.txt";
        NUMBER_OF_PROCESSES = 3;
        EXECUTION_TIME = 1000;

        printf("%s\n", FILE_NAME);
        printf("%i\n", NUMBER_OF_PROCESSES);
        printf("%i\n\n", EXECUTION_TIME);


        // Teste de inicialização
        ////////////////////////////////////////////

        pt_Vertex v = vertex_init(1, 2);

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


        // Teste de ouput dos dados
        ////////////////////////////////////////////

        puts("Cidadãos\n");
        for (size_t i = 0; i < data->NumeroCidadaos; i++)
        {
            printf("\tCidadãos: %d (%d,%d) \n",
                                                data->Cidadaos[i]->id,
                                                data->Cidadaos[i]->avenida,
                                                data->Cidadaos[i]->rua
            );
        }

        puts("Supermercados\n");
        for (size_t i = 0; i < data->NumeroSupermercados; i++)
        {
            printf("\tSupermercados: %d (%d,%d) \n", 
                                                data->Supermercados[i]->id,
                                                data->Supermercados[i]->avenida,
                                                data->Supermercados[i]->rua
            );
        }


        // Libertação de memória
        ////////////////////////////////////////////
        freeEveryEntity(data);

        freeData(data);

    } else {
        FILE_NAME = argv[1];
        NUMBER_OF_PROCESSES = atoi(argv[2]);
        EXECUTION_TIME = atoi(argv[3]);
    }



    if(checkNumberOfArguments(argc)) {
        puts("ERRO: Falta de argumentos.");
        return EXIT_FAILURE;

    } else if (checkFileName(FILE_NAME)) {
        printf("ERRO: Ficheiro \"%s\" não existe.\n", FILE_NAME);
        return EXIT_FAILURE;

    } else if (checkNumberOfProcesses(NUMBER_OF_PROCESSES)) {
        puts("ERRO: O número de processos tem de ser, pelo menos, 2.");
        return EXIT_FAILURE;
        
    } else if (EXECUTION_TIME < MINIMUM_MILISECONDS) {
        puts("ERRO: O número de milisegundos tem de ser, pelo menos, 1000.");
        return EXIT_FAILURE;

    }
    
    puts("Sucesso.");

    return 0;

}
