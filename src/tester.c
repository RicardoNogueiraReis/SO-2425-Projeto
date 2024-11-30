#include <stdio.h>
#include "adts/List.h"

int main()
{
    List testList;
    int size;
    ListElem getted;
    ListElem removed;
    ListElem a = 100;
    ListElem b = 200;
    listCreate(&testList);
    listAdd(&testList, 0, a);
    listAdd(&testList, 0, b);
    listSize(&testList, &size);
    listPrint(&testList);
    printf("Size: %d\n", size);
    listGet(&testList, 0, &getted);
    printf("Getted Element: %d\n", getted);
    listPrint(&testList);
    listRemove(&testList, 0, &removed);
    printf("Removed Element: %d\n", removed);
    listIsEmpty(&testList) ? printf("List is Empty!\n") : printf("List is not Empty!\n");
    listPrint(&testList);
    printf("Clearing the List...\n");
    listClear(&testList);
    listPrint(&testList);
    listIsEmpty(&testList) ? printf("List is Empty!\n") : printf("List is not Empty!\n");
    return 0;
}