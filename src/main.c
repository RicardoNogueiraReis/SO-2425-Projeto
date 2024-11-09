#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

#include "utils/Parameters.h"

#define ENABLE_DEBUG 0



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
        FILE_NAME = "instances_2.txt";
        NUMBER_OF_PROCESSES = 3;
        EXECUTION_TIME = 1000;

        printf("%s\n", FILE_NAME);
        printf("%i\n", NUMBER_OF_PROCESSES);
        printf("%i\n\n", EXECUTION_TIME);

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
    /*

    printf("%d\n", NUMBER_OF_PROCESSES);

	switch(NUMBER_OF_PROCESSES) {
        case 5:
            printf("argument is five.\n");
            break;

        case 6:
            printf("argument is six.\n");
            break;

        default:
            printf("Invalid argument.\n");
    }
    

    return EXIT_SUCCESS;

    // */
}
