#include <time.h>
#include "Stack.h"

#define MAX_PATH_SIZE 30

#define LIST_SUCCESS 0
#define LIST_INVALID_POSITION 1
#define LIST_IS_NULL 2

#pragma once

typedef Stack pListElem;

typedef struct pathList
{
    time_t execTime;
    int numIterations;
    int size;
    pListElem paths[MAX_PATH_SIZE];
}PathList;

typedef PathList *PtPathList;

/**
 * @brief Creates a new empty Path List with up to 4 elements from type pListElem.
 * 
 * @param pList The pList Pointer
 * @return int - Success (0) or Error (>0)
 */
int plistCreate(PtPathList pList);

/**
 * @brief Adds an element to a Path List.
 * 
 * @param pList The Path List
 * @param index Position of the Element
 * @param elem Element to be Added
 * @return int - Success (0) or Error (>0)
 */
int plistAdd(PtPathList pList, int index, pListElem elem);

/**
 * @brief Removes an element from a Path List.
 * 
 * @param pList The Path List
 * @param index Position of the Element to be Removed
 * @param remElem The Removed Element
 * @return int - Success (0) or Error (>0)
 */
int plistRemove(PtPathList pList, int index, pListElem *remElem);

/**
 * @brief Gets an element from a Path List.
 * 
 * @param pList The Path List
 * @param index Position of the Element
 * @param elem The Element
 * @return int - Success (0) or Error (>0)
 */
int plistGet(PtPathList pList, int index, pListElem* elem);

/**
 * @brief Gets the actual size of a Path List
 * 
 * @param pList The Path List
 * @param size The Size of The pList
 * @return int - Success (0) or Error (>0)
 */
int plistSize(PtPathList pList, int *size);

/**
 * @brief Verifies if a Path List is empty or not.
 * 
 * @param pList The Path List
 * @return true - if the pList is empty
 * |
 * @return false - if the pList is not empty
 */
bool plistIsEmpty(PtPathList pList);

/**
 * @brief Removes all elements from a Path List.
 * 
 * @param pList The Path List
 * @return int - Success (0) or Error (>0)
 */
int plistClear(PtPathList pList);

/**
 * @brief Prints the elements of a Path List.
 * 
 * @param pList The Path List
 */
void plistPrint(PtPathList pList);
