#include <stdlib.h>
#include <stdio.h>
#include "List.h"

#define LIST_INITIAL_SIZE 4

typedef struct list
{
    int size;
    ListElem elements[LIST_INITIAL_SIZE];
}List;

int listCreate(PtList list) {
    if (list == NULL)
        return LIST_IS_NULL;

    list->size = 0;
}

int listAdd(PtList list, int index, ListElem elem) {
    if (list == NULL)
        return LIST_IS_NULL;
    if (index > list->size || index < 0)
        return LIST_INVALID_POSITION;     

    for (int i = list->size; i > index; i--)
    {
        list->elements[i] = list->elements[i-1];
    }
    list->elements[index] = elem;
    list->size++;
    return LIST_SUCCESS;
}

int listRemove(PtList list, int index, ListElem *remElem) {
    if (list == NULL)
        return LIST_IS_NULL;
    if (index > list->size || index < 0)
        return LIST_INVALID_POSITION;
    
    *remElem = list->elements[index];
    for (int i = index; i < list->size-1; i++)
    {
        list->elements[i] = list->elements[i+1];
    }
    list->size--;
    return LIST_SUCCESS;
}

int listGet(PtList list, int index, ListElem* elem) {
    if (list == NULL)
        return LIST_IS_NULL;
    if (index > list->size || index < 0)
        return LIST_INVALID_POSITION;

    *elem = list->elements[index];
    return LIST_SUCCESS;
}

int listSize(PtList list, int *size) {
    if (list == NULL)
        return LIST_IS_NULL;
    
    *size = list->size;
    return LIST_SUCCESS;
}

bool listIsEmpty(PtList list) {
    if (list == NULL)
        return true;

    return list->size == 0;
}

int listClear(PtList list) {
    if (list == NULL)
        return LIST_IS_NULL;

    list->size = 0;
}

void listPrint(PtList list) {
    if (list == NULL)
        return;
    
    if (listIsEmpty(list))
    {
        printf("The list is empty!\n");
        return;
    }
    
    printf("List Elements: %d", list->elements[0]);
    for (int i = 1; i < list->size; i++)
    {
        printf(" | %d", list->elements[i]);
    }
    printf("\n");
}