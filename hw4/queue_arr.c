#include "queue_arr.h"

#include <stdlib.h>


struct queueArr* queueArrCreate(void)
{    
    struct queueArr* q = malloc(sizeof(struct queueArr)); 
    q->arr = darrayCreate(0); 
    return q;
}

int queueArrDestroy(struct queueArr* queue)
{
    if (!queue) return 0; 
    
    darrayDestroy(queue->arr);
    // free(queue->arr);
    queue->arr = NULL; 
    free(queue);
    queue = NULL;
    return 1;
}

int queueArrEnqueue(struct queueArr* queue, int newVal)
{
    if (!queue) return 0; 
   
    darrayAppend(queue->arr, newVal);
    return 1;
}

int queueArrDequeue(struct queueArr* queue, int* val)
{
    if (!queue) return 0; 
    if (darrayLength(queue->arr) == 0) return 0; 

    darrayGet(queue->arr, 0, val);
    darrayDelete(queue->arr, 0);
    return 1;
}

unsigned queueArrLength(const struct queueArr* queue)
{
    if (!queue) return 0; 
    return darrayLength(queue->arr);
}
