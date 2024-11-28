#include <stdbool.h>
#include "esquina.h"

#define STACK_SUCCESS 0
#define STACK_IS_NULL 1
#define STACK_IS_EMPTY 2
#define STACK_IS_FULL 3

#pragma once

typedef struct stack Stack;

typedef Stack* PtStack;

typedef pt_Esquina StackElem;

/**
 * @brief Creates a new empty stack with up to 1000 elements from type StackElem.
 * 
 * @param stack The Stack Pointer
 * @return int - Success (0) or Error (>0)
 */
int stackCreate(PtStack stack);

/**
 * @brief Adds an element to the top of a stack.
 * 
 * @param stack The Stack
 * @param elem Element to be Added
 * @return int - Success (0) or Error (>0)
 */
int stackPush(PtStack stack, StackElem elem);

/**
 * @brief Removes the top element from a stack.
 * 
 * @param stack The Stack
 * @param remElem The Removed Element
 * @return int - Success (0) or Error (>0)
 */
int stackPop(PtStack stack, StackElem* remElem);

/**
 * @brief Gets the top element of a stack.
 * 
 * @param stack The Stack
 * @param elem The Element
 * @return int - Success (0) or Error (>0)
 */
int stackPeek(PtStack stack, StackElem* elem);

/**
 * @brief Gets the actual size of a stack
 * 
 * @param stack The Stack
 * @param size The Size of The Stack
 * @return int - Success (0) or Error (>0)
 */
int stackSize(PtStack stack, int *size);

/**
 * @brief Verifies if a stack is empty or not.
 * 
 * @param stack The Stack
 * @return true - if the stack is empty
 * |
 * @return false - if the stack is not empty
 */
bool stackIsEmpty(PtStack stack);

/**
 * @brief Removes all elements from a stack.
 * 
 * @param stack The Stack
 * @return int - Success (0) or Error (>0)
 */
int stackClear(PtStack stack);

/**
 * @brief Prints the elements of a stack. (Prints the Best Soluction of the Citizen)
 * 
 * @param stack The Stack
 */
void stackPrint(PtStack stack);