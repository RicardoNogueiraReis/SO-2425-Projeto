#include <stdlib.h>
#include "Stack.h"

#define MAX_STACK_SIZE 1000

typedef struct stack
{
    int size;
    StackElem elements[MAX_STACK_SIZE];
} Stack;

int stackCreate(PtStack stack) {
    if (stack == NULL)
        return STACK_IS_NULL;
    
    stack->size=0;
    return STACK_SUCCESS;
}

int stackPush(PtStack stack, StackElem elem) {
    if (stack == NULL)
        return STACK_IS_NULL;
    if (stack->size == MAX_STACK_SIZE)
        return STACK_IS_FULL;
    
    stack->elements[stack->size++];
    return STACK_SUCCESS;
}

int stackPop(PtStack stack, StackElem* remElem) {
    if (stack == NULL)
        return STACK_IS_NULL;

    if (stackIsEmpty(stack))
        return STACK_IS_EMPTY;
    
    *remElem = stack->elements[--stack->size];
    return STACK_SUCCESS;
}

int stackPeek(PtStack stack, StackElem* elem) {
    if (stack == NULL)
        return STACK_IS_NULL;

    if (stackIsEmpty(stack))
        return STACK_IS_EMPTY;

    *elem = stack->elements[stack->size-1];
    return STACK_SUCCESS;
}

int stackSize(PtStack stack, int *size) {
    if (stack == NULL)
        return STACK_IS_NULL;

    *size = stack->size;
    return STACK_SUCCESS;
}

bool stackIsEmpty(PtStack stack) {
    if (stack == NULL)
        return true;

    return stack->size == 0;
}

int stackClear(PtStack stack) {
    if (stack == NULL)
        return STACK_IS_NULL;

    stack->size = 0;
    return STACK_SUCCESS;
}

void stackPrint(PtStack stack) {
    if (stack == NULL)
        return;
    
    if (stackIsEmpty(stack))
    {
        printf("The stack is empty!\n");
        return;
    }
    
    printf("Caminho Solução: %d", stack->elements[0]);
    for (int i = 0; i < stack->size; i++)
    {
        printf(" | %d", stack->elements[i]);
    }
    printf("\n");
}