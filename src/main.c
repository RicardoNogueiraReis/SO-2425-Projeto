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

/**
 * @brief Main function
 *
 * @param argc Number of arguments provided
 * @param argv Array of arguments provided
 * @return int EXIT_SUCCESS when finished, else otherwise.
 */
int main(int argc, char **argv)
{
    /*
    const char *FILE_NAME = argv[1];
    const int NUMBER_OF_PROCESSES = atoi(argv[2]);
    const int EXECUTION_TIME = atoi(argv[3]);
    */

    argc = 4;
    const char *FILE_NAME = "instances_2.txt";
    const int NUMBER_OF_PROCESSES = 3;
    const int EXECUTION_TIME = 1000;

    if (checkNumberOfArguments(argc)) {
        puts("ERRO: Falta de argumentos.");
        return EXIT_FAILURE;

    }
    else if (checkFileName(FILE_NAME)) {
        printf("ERRO: Ficheiro \"%s\" não existe.\n", FILE_NAME);
        return EXIT_FAILURE;

    }
    else if (checkNumberOfProcesses(NUMBER_OF_PROCESSES)) {
        puts("ERRO: O número de processos tem de ser, pelo menos, 2.");
        return EXIT_FAILURE;

    }
    else if (EXECUTION_TIME < MINIMUM_MILISECONDS) {
        puts("ERRO: O número de milisegundos tem de ser, pelo menos, 1000.");
        return EXIT_FAILURE;

    }

    /* Memória partilhada */    
    /*
    int size = 64;
    int protection = PROT_READ | PROT_WRITE;

    int visibility = 1111 | MAP_SHARED;
    //int visibility = MAP_ANONYMOUS | MAP_SHARED;

    void *solucao = mmap(NULL, size, protection, visibility, 0, 0);

    // */

    int pids[NUMBER_OF_PROCESSES];


    /* Dados do problema */
    pt_FileTestData data = readFileData(FILE_NAME);

    pt_Esquina **mapa = mapa_init(data->TotalAvenidas, data->TotalRuas);

    print_mapa(mapa, data->TotalAvenidas, data->TotalRuas);

    findSafeCitizen(0, mapa, data);

    /* FSCS */
    /*
    int maxSolutions = calculateMaxSolutions(data->NumeroCidadaos, data->NumeroSupermercados);

    void* solutionList = NULL; // ArrayList, talvez?

    void* listaNosVisitados = NULL;    // Lista de nós visitados

    int numSolucoes = 0;               // Número de soluções
    


    for (int i = 0; i < NUMBER_OF_PROCESSES; i++) {

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
    freeMapa(mapa, data->TotalAvenidas, data->TotalRuas);
    puts("Sucesso.");

    return EXIT_SUCCESS;
}
