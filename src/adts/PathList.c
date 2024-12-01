#include <stdlib.h>
#include <stdio.h>
#include "PathList.h"

int plistCreate(PtPathList plist) {
    if (plist == NULL)
        return LIST_IS_NULL;
    
    for (int i = 0; i < MAX_PATH_SIZE; i++)
    {
        plist->paths[i].size = 0;
    }
    
    plist->size = 0;
    return LIST_SUCCESS;
}

int plistAdd(PtPathList plist, int index, pListElem elem) {
    if (plist == NULL)
        return LIST_IS_NULL;
    if (index >= MAX_PATH_SIZE || index < 0)
        return LIST_INVALID_POSITION;

    if (plist->paths[index].size == 0)
        plist->size++;

    plist->paths[index] = elem;
    
    return LIST_SUCCESS;
}

int plistRemove(PtPathList plist, int index, pListElem *remElem) {
    if (plist == NULL)
        return LIST_IS_NULL;
    if (index >= MAX_PATH_SIZE || index < 0)
        return LIST_INVALID_POSITION;
    
    *remElem = plist->paths[index];
    
    plist->paths[index].size = 0;
    
    plist->size--;
    return LIST_SUCCESS;
}

int plistGet(PtPathList plist, int index, pListElem* elem) {
    if (plist == NULL)
        return LIST_IS_NULL;
    if (index >= MAX_PATH_SIZE || index < 0)
        return LIST_INVALID_POSITION;

    *elem = plist->paths[index];
    return LIST_SUCCESS;
}

int plistSize(PtPathList plist, int *size) {
    if (plist == NULL)
        return LIST_IS_NULL;
    
    *size = plist->size;
    return LIST_SUCCESS;
}

bool plistIsEmpty(PtPathList plist) {
    if (plist == NULL)
        return true;

    return plist->size == 0;
}

int plistClear(PtPathList plist) {
    if (plist == NULL)
        return LIST_IS_NULL;

    plist->size = 0;
}

void plistPrint(PtPathList plist) {
    if (plist == NULL)
        return;
    
    if (listIsEmpty(plist))
    {
        printf("The plist is empty!\n");
        return;
    }
    
    printf("Lista de Soluções: ");
    for (int i = 0; i < MAX_PATH_SIZE; i++)
    {
        if (plist->paths[i].size == 0)
            continue;
        
        printf("\nCidadão %d -> ", i);
        stackPrint(&plist->paths[i]);
    }
    printf("\n");
}