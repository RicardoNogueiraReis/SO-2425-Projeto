#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/mman.h>
#include <time.h>

#include "adts/esquina.h"
#include "adts/esquina.h"
#include "algoritmos/fscs.h"
#include "utils/data.h"
#include "utils/parameters.h"
#include "adts/Stack.h"
#include "PathList.h"
#include "algoritmos/fscs.h"

#define ONE_MILISECOND 1000
#define MAXIMUM_SOLUCTIONS 30

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
    time_t parentTime = time(NULL); //Timestamp

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

    /* Memória partilhada */

    int size = sizeof(PathList);
    int protection = PROT_READ | PROT_WRITE;

    int visibility = MAP_ANONYMOUS | MAP_SHARED;

    void *shmem = mmap(NULL, size, protection, visibility, 0, 0);

    const PathList finalPathList;
    plistCreate(&finalPathList);

    memcpy(shmem, &finalPathList, sizeof(PathList));

    PtPathList sharedPathList = (PtPathList) shmem;

    int pids[NUMBER_OF_PROCESSES];

    /* Semáforos */
    sem_unlink("shared_memory");

    sem_t *shared_memory = sem_open("shared_memory", O_CREAT, 0644, 1);
    
    
    // Dados do problema
    FileTestData data;

    readFileData(&data, FILE_NAME);

    int maxSolutions = calculateMaxSolutions(data.NumeroCidadaos, data.NumeroSupermercados);
    
    Stack solutionList[MAXIMUM_SOLUCTIONS];
    for(int i = 0; i < maxSolutions; i++) {
        stackCreate(&solutionList[i]);
    }

    for (int i = 0; i < NUMBER_OF_PROCESSES; i++) {

        pids[i] = fork();

        if (pids[i] == 0) {
            srand(time(NULL) ^ (getpid()<<16));

            time_t processTime = time(NULL);

            int nSoluctions;

            for (int i = 1; i < 10000 || difftime(processTime, parentTime) >= EXECUTION_TIME; i++)
            {
                time_t execTime = time(NULL);

                PathList pathList;
                plistCreate(&pathList);

                MapaEsquina mapa;
                mapaCreate(&mapa, data.TotalAvenidas, data.TotalRuas);

                //Implement FSCS
                while (plistSize(&pathList, &nSoluctions) == 0 && nSoluctions < maxSolutions || difftime(processTime, parentTime) >= EXECUTION_TIME)
                {
                    int citizenID = (rand() % data.NumeroCidadaos + 1);
                    if (pathList.paths[citizenID].size == 0)
                        findSafeCitizen(citizenID, &mapa, &data, &pathList);
                }   

                int newSoluctionSize;
                plistSize(&pathList, &newSoluctionSize);

                sem_wait(shared_memory);

                int actualSoluctionSize;
                plistSize(sharedPathList, &actualSoluctionSize);

                if (actualSoluctionSize < newSoluctionSize)
                    memcpy(sharedPathList, &newSoluctionSize, sizeof(PathList));

                sem_post(shared_memory);
            }
            exit(0);
        }
    }

    puts("\nSucesso.");

    return EXIT_SUCCESS;
}
