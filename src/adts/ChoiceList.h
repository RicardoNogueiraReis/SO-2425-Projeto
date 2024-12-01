#include <stdbool.h>

#define LIST_SUCCESS 0
#define LIST_INVALID_POSITION 1
#define LIST_IS_NULL 2

#define MAX_LIST_SIZE 4

#pragma once

typedef int ListElem;

typedef struct list
{
    int size;
    ListElem elements[MAX_LIST_SIZE];
}ChoiceList;

typedef ChoiceList *PtChoiceList;

/**
 * @brief Creates a new empty list with up to 4 elements from type ListElem.
 * 
 * @param list The List Pointer
 * @return int - Success (0) or Error (>0)
 */
int listCreate(PtChoiceList list);

/**
 * @brief Adds an element to a list.
 * 
 * @param list The List
 * @param index Position of the Element
 * @param elem Element to be Added
 * @return int - Success (0) or Error (>0)
 */
int listAdd(PtChoiceList list, int index, ListElem elem);

/**
 * @brief Removes an element from a list.
 * 
 * @param list The List
 * @param index Position of the Element to be Removed
 * @param remElem The Removed Element
 * @return int - Success (0) or Error (>0)
 */
int listRemove(PtChoiceList list, int index, ListElem *remElem);

/**
 * @brief Gets an element from a list.
 * 
 * @param list The List
 * @param index Position of the Element
 * @param elem The Element
 * @return int - Success (0) or Error (>0)
 */
int listGet(PtChoiceList list, int index, ListElem* elem);

/**
 * @brief Gets the actual size of a list
 * 
 * @param list The List
 * @param size The Size of The List
 * @return int - Success (0) or Error (>0)
 */
int listSize(PtChoiceList list, int *size);

/**
 * @brief Verifies if a list is empty or not.
 * 
 * @param list The List
 * @return true - if the list is empty
 * |
 * @return false - if the list is not empty
 */
bool listIsEmpty(PtChoiceList list);

/**
 * @brief Removes all elements from a list.
 * 
 * @param list The List
 * @return int - Success (0) or Error (>0)
 */
int listClear(PtChoiceList list);

/**
 * @brief Prints the elements of a list.
 * 
 * @param list The List
 */
void listPrint(PtChoiceList list);