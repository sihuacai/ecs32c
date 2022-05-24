#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H

#include "darray.h"

/*
 * Queue implemented with an array.
 * Since you cannot modify this file, you cannot change the members
 * of this struct.
 */
struct queueArr
{
    struct darray* arr;
};

/**
 * Creates empty queue and returns a pointer to it.
 */
struct queueArr* queueArrCreate(void);

/**
 * Deallocates all dynamically allocated memory associated with the queue.
 * Returns 0 if @queue is NULL; returns 1 otherwise.
 */
int queueArrDestroy(struct queueArr* queue);

/**
 * Adds @newVal to the back of the queue.
 * Returns 0 if @queue is NULL and 1 otherwise.
 */
int queueArrEnqueue(struct queueArr* queue, int newVal);

/**
 * Removes value at the front of the queue and places it in the variable
 * referenced by @val.
 * Returns 0 if given a null pointer or if @queue is empty.
 * Returns 1 otherwise.
 */
int queueArrDequeue(struct queueArr* queue, int* val);

/**
 * Returns number of elements in the queue. Returns 0 if @queue is NULL.
 */
unsigned queueArrLength(const struct queueArr* queue);

#endif  // QUEUE_ARR_H
