#ifndef DARRAY_H
#define DARRAY_H

/**
 * Dynamic array, i.e. an array whose size can be changed with a
 * convenient interface.
 */
struct darray;

/**
 * Creates a dynamic array of the given size.
 * Does not initialize the elements of the array to any value.
 * Returns a pointer to the created instance of struct darray.
 *
 *
 * Hints:
 *
 * 1\. Since you are creating a new object (the instance of struct darray)
 *     in this function, it must be dynamically allocated.
 *
 * 2\. Presumably, one of the members of this instance should be an
 *     underlying dynamically allocated array.
 */
struct darray* darrayCreate(unsigned initialSize);

/**
 * Deallocates all dynamically allocated memory associated with the
 * given dynamic array.
 * Returns 0 if @array is NULL; returns 1 otherwise.
 */
int darrayDestroy(struct darray* array);

/**
 * Retrieves the value at the given index in the dynamic array and
 * places it in the variable referenced by @val.
 * Returns 0 if given any null pointer or if @index is out-of-range;
 * returns 1 otherwise.
 */
int darrayGet(const struct darray* array, unsigned index, int* val);

/**
 * Sets the value at the given index in the dynamic array to @newVal.
 * Returns 0 if @array is NULL or if @index is out-of-range;
 * returns 1 otherwise.
 */
int darraySet(struct darray* array, unsigned index, int newVal);

/**
 * Returns the number of elements in the array.
 * Returns 0 if given a null pointer.
 */
unsigned darrayLength(const struct darray* array);

/**
 * Deletes the element at the given index (and slides the elements after
 * this deleted element one index down).
 * Returns 0 if @array is NULL or if @index is out-of-range;
 * returns 1 otherwise.
 */
int darrayDelete(struct darray* array, unsigned index);

/**
 * Appends @newVal to the back of the array.
 * Returns 0 if @array is NULL; returns 1 otherwise.
 */
int darrayAppend(struct darray* array, int newVal);

/**
 * Inserts @newVal at the given index (and slides the elements that are
 * already at that index and after it one index up).
 * If @index is equal to the length of the array, then this function
 * behaves like darrayAppend().
 * Returns 0 if @array is NULL or if @index is out-of-range;
 * returns 1 otherwise.
 */
int darrayInsert(struct darray* array, unsigned index, int newVal);

/**
 * Returns a copy of the given instance of struct darray
 * or NULL if @array is NULL.
 */
struct darray* darrayCopy(const struct darray* array);

/**
 * Applies the function referenced by @map to each element of @array.
 * Returns 0 if given a null pointer and 1 otherwise.
 */
int darrayMap(struct darray* array, int (*map)(int));

#endif  // DARRAY_H
