#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Parameters.h"

int checkNumberOfArguments(const int numberArgs) {
    return numberArgs < MINIMUM_NUMBER_OF_ARGUMENTS;

}

int checkFileName(const char* fileName) {
    char fileDirectory[PATH_FILENAME_SIZE] = "../file_tests/";

    strcat(fileDirectory, fileName);

    FILE *file = fopen(fileDirectory, "r");

    if(file) {
        fclose(file);
        return 0;
    }

    return 1; // Erro
}

int checkNumberOfProcesses(const int numberProcesses) {
    return numberProcesses < MINIMUM_NUMBER_OF_PROCESSES;

}
