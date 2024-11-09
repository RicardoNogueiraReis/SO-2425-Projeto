#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

/**
 * @brief Main function
 * 
 * @param argc Number of arguments provided
 * @param argv Array of arguments provided
 * @return int EXIT_SUCCESS when finished, else otherwise.
 */
int main(int argc, char **argv)
{
    if(argc < 2) {
        puts("Nenhum argumento foi fornecido.");
        return 1;
    }

    const int NUMBER_OF_PROCESSES = atoi(argv[1]);

    printf("%d\n", NUMBER_OF_PROCESSES);

	switch(NUMBER_OF_PROCESSES){
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
}
