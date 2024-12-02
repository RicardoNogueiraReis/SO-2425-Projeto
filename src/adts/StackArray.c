#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

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
    
    stack->elements[stack->size++] = elem;
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
    
    printf("Caminho Solução: ");
    print_esquina(&stack->elements[0]);
    for (int i = 1; i < stack->size; i++)
    {
        printf(" | ");
        print_esquina(&stack->elements[i]);
    }
    printf("\n");
}