#include "stack_arr.h"

#include <stdlib.h>

struct stackArr* stackArrCreate(void)
{
    struct stackArr* s = malloc(sizeof(struct stackArr)); 
    s->arr = darrayCreate(0); 
    return s;
}

int stackArrDestroy(struct stackArr* stack)
{
    if (!stack) return 0; 
    
    darrayDestroy(stack->arr); 
    free(stack); 
    stack = NULL; 
    return 1;
}

int stackArrPush(struct stackArr* stack, int newVal)
{
    if (!stack) return 0; 

    darrayAppend(stack->arr, newVal); 
    return 1;
}

int stackArrPop(struct stackArr* stack, int* val)
{
    if (!stack) return 0; 

    unsigned len = darrayLength(stack->arr); 
    if (len == 0) return 0;
    
    darrayGet(stack->arr, len - 1, val); 
    darrayDelete(stack->arr, len - 1); 
    return 1;
}

unsigned stackArrLength(const struct stackArr* stack)
{
    if (!stack) return 0; 
    return darrayLength(stack->arr);
}
