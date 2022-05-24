#include "darray.h"

#include <stdlib.h>

struct darray
{
    int* values; 
    unsigned length; 
};

struct darray* darrayCreate(unsigned initialSize)
{
    struct darray* d = malloc(sizeof(struct darray));
    d->values = malloc(initialSize * sizeof(int)); 
    d->length = initialSize; 
    return d;
}

int darrayDestroy(struct darray* array)
{
    if (!array) return 0; 
    
    free(array->values);
    array->length = 0; 
    free(array); 
    array = NULL; 
    return 1;
}

int darrayGet(const struct darray* array, unsigned index, int* val)
{
    if (!array) return 0;
    if (index >= array->length || index < 0) return 0; 

    *val = array->values[index];    
    return 1;
}

int darraySet(struct darray* array, unsigned index, int newVal)
{
    if (!array) return 0; 
    if (index >= array->length || index < 0) return 0; 

    array->values[index] = newVal;
    return 1;
}

unsigned darrayLength(const struct darray* array)
{
    if (!array) return 0; 
    return (array->length);
}

int darrayDelete(struct darray* array, unsigned index)
{
    if (!array) return 0; 
    if (index >= array->length || index < 0) return 0; 

    for (unsigned i = index; i < array->length; i++)       
        array->values[i] = array->values[i+1];
   
    (array->values)[array->length] = 0; 
    array->length = array->length - 1;
    
    return 1;
}

int darrayAppend(struct darray* array, int newVal)
{
    if (!array) return 0; 
    
    array->length = array->length + 1; 
    array->values = realloc(array->values, array->length * sizeof(int)); 
    array->values[array->length - 1] = newVal; 
    return 1;
}

int darrayInsert(struct darray* array, unsigned index, int newVal)
{
    if (!array) return 0; 
    if (index > array->length || index < 0) return 0; 
    
    array->length = (array->length) + 1; 
    array->values = realloc(array->values, array->length * sizeof(int)); 

    int replace = newVal; 
    int tmp;
    for (unsigned i = index; i < array->length - 1; i++)
    {
        tmp = array->values[i];
        array->values[i] = replace; 
        replace = tmp; 
    }
    array->values[array->length - 1] = replace;
    return 1;
}

struct darray* darrayCopy(const struct darray* array)
{
    if (!array) return 0; 

    struct darray* copy = malloc(sizeof(struct darray));
    copy->values = malloc(array->length * sizeof(int)); 
    copy->length = array->length;
    
    for (unsigned i = 0; i < array->length; i++)
        copy->values[i] = array->values[i];
    
    return copy;
}

int darrayMap(struct darray* array, int (*map)(int))
{
    if (!array) return 0; 
    if (!(*map)) return 0; 

    for (unsigned i = 0; i < array->length; i++) 
        array->values[i] = (*map)(array->values[i]);

    return 1;
}
