#ifndef STACK_ARR_H
#define STACK_ARR_H

#include "darray.h"

/**
 * Stack implemented with an array.
 * Since you cannot modify this file, you cannot change the members
 * of this struct.
 */
struct stackArr
{
    struct darray* arr;
};

/**
 * Creates empty stack and returns a pointer to it.
 */
struct stackArr* stackArrCreate(void);

/**
 * Deallocates all dynamically allocated memory associated with the stack.
 * Returns 0 if @stack is NULL; returns 1 otherwise.
 */
int stackArrDestroy(struct stackArr* stack);

/**
 * Adds @newVal to the top of the stack.
 * Returns 0 if @stack is NULL and 1 otherwise.
 */
int stackArrPush(struct stackArr* stack, int newVal);

/**
 * Removes value at the top of the stack and places it in the variable
 * referenced by @val.
 * Returns 0 if given a null pointer or if @stack is empty.
 * Returns 1 otherwise.
 */
int stackArrPop(struct stackArr* stack, int* val);

/**
 * Returns number of elements in the stack. Returns 0 if @stack is NULL.
 */
unsigned stackArrLength(const struct stackArr* stack);

#endif  // STACK_ARR_H
