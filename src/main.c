#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/wait.h>

#include "adts/esquina.h"
#include "adts/esquina.h"
#include "algoritmos/fscs.h"
#include "utils/data.h"
#include "utils/parameters.h"
#include "adts/Stack.h"
#include "adts/PathList.h"
#include "algoritmos/fscs.h"
#include "utils/timeMilis.h"
#include "adts/ChoiceList.h"
#include "utils/resultTable.h"

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
    ResultTable results[10];
    Millis avgExecTime = 0;
    int avgNIterations = 0;
    int nBestSoluction = 0;

    const char *FILE_NAME = argv[1];
    const int NUMBER_OF_PROCESSES = atoi(argv[2]);
    const int EXECUTION_TIME = atoi(argv[3]);
    
    for (int t = 0; t < 10; t++)
    {
        TimeMillis parentTime; //Timestamp
        createTime(&parentTime);

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

        PathList finalPathList;
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

                TimeMillis processTime, execTime;

                PathList pathList;

                MapaEsquina mapa;

                ChoiceList chooseCitizenList;

                int nSoluctions = 0;

                for(int nIterations = 1; nSoluctions < maxSolutions && pathList.execTime < EXECUTION_TIME; nIterations++)
                {
                    plistCreate(&pathList);

                    mapaCreate(&mapa, data.TotalAvenidas, data.TotalRuas);

                    for (int i = 0; i < data.NumeroSupermercados; i++)
                    {
                        mapaSetEsquinaSuperMarket(&mapa, data.Supermercados[i].avenida, data.Supermercados[i].rua);                  
                    }
                    

                    listCreate(&chooseCitizenList);
                    for (int i = 0; i < data.NumeroCidadaos; i++)
                    {
                        listAdd(&chooseCitizenList, i, data.Cidadaos[i].id);
                    }
                    
                    while(!listIsEmpty(&chooseCitizenList))
                    {
                        int citizenID, remainingCitizens;
                        listSize(&chooseCitizenList, &remainingCitizens);
                        listGet(&chooseCitizenList, (rand() % remainingCitizens), &citizenID);

                        findSafeCitizen(citizenID, &mapa, &data, &pathList);

                        listRemove(&chooseCitizenList, citizenID, NULL);
                    }

                    createTime(&processTime);
                    createTimeFromTimeDiff(&execTime, &parentTime, &processTime);
                    getTimeInMilis(&execTime, &pathList.execTime);
                    
                    pathList.numIterations = nIterations;
                    plistSize(&pathList, &nSoluctions);

                    sem_wait(shared_memory);

                    int actualSoluctionSize;
                    plistSize(sharedPathList, &actualSoluctionSize);

                    if (actualSoluctionSize < nSoluctions)
                        memcpy(sharedPathList, &pathList, sizeof(PathList));

                    sem_post(shared_memory);
                }
                
                exit(0);
            }
            else
                wait(NULL);
        }

        Millis tExecTimeMS;
        TimeMillis parentTime2, tExecTime;
        createTime(&parentTime2);
        createTimeFromTimeDiff(&tExecTime, &parentTime, &parentTime2);
        getTimeInMilis(&tExecTime, &tExecTimeMS);

        int nCidadaosSafos;
        plistSize(sharedPathList, &nCidadaosSafos);

        if (nCidadaosSafos == maxSolutions)
            nBestSoluction++;
        
        avgExecTime += sharedPathList->execTime;
        avgNIterations += sharedPathList->numIterations;
        
        resultTableCreate(&results[t], t+1, FILE_NAME, tExecTimeMS, NUMBER_OF_PROCESSES, nCidadaosSafos, *sharedPathList, sharedPathList->numIterations, sharedPathList->execTime);
    }
    
    for (int t = 0; t < 10; t++)
    {
        resultTablePrint(&results[t]);
        printf("\n____________________________________________________________________\n");
    }

    printf("Tempo Médio de Solução: %.2f ms\n", (float) avgExecTime / 10);
    printf("Número Médio de Iterações: %.2f\n", (float) avgNIterations / 10);
    printf("Número de Soluções Ótimas Encontradas: %d\n", nBestSoluction);
    
    return EXIT_SUCCESS;
}
