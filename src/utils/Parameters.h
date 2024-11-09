#include <stdio.h>
#include <stdlib.h>
#pragma once

#define MINIMUM_MILISECONDS 1000
#define MINIMUM_NUMBER_OF_ARGUMENTS 4
#define MINIMUM_NUMBER_OF_PROCESSES 2
#define PATH_FILENAME_SIZE 31

/**
 * @brief Checks if the number of arguments given while initiating the program is enough.
 * 
 * @param numberArgs Number of arguments passed
 * @return int 0 - if all four are present, else if there's arguments lacking.
 */
int checkNumberOfArguments(int numberArgs);

/**
 * @brief Checks if the file exists by trying to open it
 * 
 * @param fileName Name of the file to be read
 * @return int 0 - if file exists and can be opened, else if it doesn't exist nor can it be opened
 */
int checkFileName(const char* fileName);

int checkNumberOfProcesses(int numberProcesses);