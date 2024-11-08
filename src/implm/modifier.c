/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:                                                                *
 * modifier.c                                                                *
 *                                                                           *
 * PURPOSE:                                                                  *
 * Includes functions that modify the vector.                                *
 *                                                                           *
 * EXTERNAL REFERENCES:                                                      *
 * 'size_t' type        (from <stdlib.h>)                                    *
 * 'free' function      (from <stdlib.h>)                                    *
 * 'malloc' function    (from <stdlib.h>)                                    *
 * 'perror' function    (from <stdio.h>)                                     *
 * 'vec_t' struct         (from "structs.h")                                 *
 * 'elem_t' struct        (from "structs.h")                                 *
 *                                                                           *
 * NOTES:                                                                    *
 * Modifications may include change in size or specific elements.            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>

#include "devhelper.h"
#include "structs.h"
#include "vector.h"

/** Deletes all elements in the vector. */
void
clear_v (vec_t *vec)
{
    // cleanup function
    if (vec->size < 2) {
        free (vec->front);
        return;
    }
    struct elem_t *ptr1 = vec->front;
    struct elem_t *ptr2 = vec->front;
    for (size_t i = 0; i < vec->size; ++i) {
        ptr1 = ptr2;
        ptr2 = ptr1->next;
        free (ptr1);
    }
    if (ptr2 == NULL)
        free (ptr2);

    vec->front = NULL;
}

/**
 * Fills an empty vector to a specified size and initializes all values to a
 * specified value
 * @param size The size to assign to
 * @param data The data to assign each element to
 * */
void
assign_v (vec_t *vec, size_t size, int data)
{
    // if size is negative or too large that it overflows the size limit
    if (size < 0 || size > SIZE_MAX) {
        perror ("[ \033[1;31mFAILED\033[0m ] assign_v: requested size out of "
                "bounds\n");
        return;
    }

    // if the vector already contains elements, dont do anything
    if (vec->front != NULL || vec->size != 0)
        return;

    vec->size = size;
    struct elem_t *new = (struct elem_t *)malloc (sizeof (struct elem_t));
    if (new == NULL) {
        perror ("[ \033[1;31mFAILED\033[0m ] malloc: memory request service "
                "failed\n");
        return;
    }
    vec->front = new;
    struct elem_t *iter = vec->front;
    for (size_t i = 1; i < size; ++i) {
        struct elem_t *new_next
            = (struct elem_t *)malloc (sizeof (struct elem_t));
        if (new_next == NULL) {
            perror ("[ \033[1;31mFAILED\033[0m ] malloc: memory request "
                    "service failed\n");
            return;
        }

        new_next->data = data;
        iter->next = new_next;
        iter = new_next;
    }
}

/**
 * Resizes the vector and initiates all values to a specific value
 * @param size The size to resize to
 * @param data The data to assign each new value to
 * */
void
resize_v (vec_t *vec, size_t size, int data)
{
    // if size is negative or too large that it overflows the size_t limit
    if (size < 0 || size > SIZE_MAX) {
        perror ("[ \033[1;31mFAILED\033[0m ] resize_v: requested size out of "
                "bounds\n");
        return;
    }

    // if the requested size = current size, do nothing
    if (vec->size == size)
        return;

    // if the vector wants to be shrunk,
    // pop the elements overflowing the size
    if (size < vec->size) {
        while (vec->size > size)
            popb_v (vec);

    } else { // if the vector wants to be enlarged, add initialized elements to
             // end
        while (vec->size < size)
            pushb_v (vec, data);
    }
}

/**
 * Adds an element to the end
 * @param data The data to append
 * */
void
pushb_v (vec_t *vec, int data)
{
    struct elem_t *new = (struct elem_t *)malloc (sizeof (struct elem_t));
    if (new == NULL) {
        perror ("[ \033[1;31mFAILED\033[0m ] malloc: memory request service "
                "failed\n");
        return;
    }

    if (vec->front == NULL) {
        new->data = data;
        vec->front = new;
        new->next = NULL;
    } else {
        // find the position
        struct elem_t *cur = vec->front;
        struct elem_t *prev = vec->front;
        for (size_t i = 0; i < vec->size; ++i) {
            prev = cur;
            cur = cur->next;
        }

        // set the values
        cur = new;
        cur->data = data;
        prev->next = cur;
    }

    ++(vec->size);
}

/**
 * @param pos The position to get
 * @return A pointer to the value at a certain location.
 * */
int *
get_v (vec_t *vec, size_t pos)
{
    if (pos < 0 || pos >= vec->size) {
        perror ("[ \033[1;31mFAILED\033[0m ] get_v: requested size of out "
                "bounds\n");
        return 0;
    }

    struct elem_t *iter = vec->front;
    for (size_t i = 0; i < pos; ++i) {
        iter = iter->next;
    }

    return &(iter->data);
}

/**
 * Inserts an element in a specified position
 * @param pos The position to insert at
 * @param data The data to insert
 * */
struct elem_t *
insert_v (vec_t *vec, size_t pos, int data)
{
    if (pos < 0
        || pos >= vec->size) { // if position is negative or larger than the
        // vector size handle the out of bounds error
        perror ("[ \033[1;31mFAILED\033[0m ] insert_v: requested size out of "
                "bounds\n");
        return NULL;
    }

    // get to insertion position
    struct elem_t *iter = vec->front;
    for (size_t i = 0; i < pos - 1; ++i) {
        iter = iter->next;
    }

    // set the values and link
    struct elem_t *new = (struct elem_t *)malloc (sizeof (struct elem_t));
    if (new == NULL) {
        perror ("[ \033[1;31mFAILED\033[0m ] malloc: memory request service "
                "failed\n");
        return NULL;
    }

    new->data = data;
    new->next = iter->next;
    iter->next = new;

    return new;
}

/**
 * Swaps the value of two elements in a specified position
 * @param i1 The index of the first element
 * @param i2 The index of the second element
 * */
void
swap_v (vec_t *vec, size_t i1, size_t i2)
{
    if (i1 < 0 || i2 < 0 || i1 >= vec->size
        || i2 >= vec->size) { // if any requested index is negative or greater
        // than the size, handle the out of bounds error
        perror ("[ \033[1;31mFAILED\033[0m ] swap_v: requested size out of "
                "bounds\n");
        return;
    }

    // make i1 always smaller than i2
    if (i1 > i2) {
        int tmp = i1;
        i1 = i2;
        i2 = tmp;
    }

    // read the data

    // get to the first index and read value
    struct elem_t *iter = iter_begin (vec, i1);

    int data1 = iter->data;

    for (size_t i = i1; i < i2; ++i)
        iter = iter->next;

    int data2 = iter->data;

    // set the data

    // get to the first index and change to the swapped value
    iter = iter_begin (vec, i1);

    iter->data = data2;

    for (size_t i = i1; i < i2; ++i)
        iter = iter->next;

    iter->data = data1;
}

/**
 * Deletes an element in a specified position
 * @param pos The position to erase
 * */
void
erase_v (vec_t *vec, size_t pos)
{
    // if position is negative or larger than the vector size,
    // handle the out of bounds
    if (pos < 0 || pos >= vec->size) {
        perror ("[ \033[1;31mFAILED\033[0m ] erase_v: requested size out of "
                "bounds\n");
        return;
    }

    // points to the address of the element to be removed
    struct elem_t **indirect = &vec->front;

    for (size_t i = 0; i < pos; ++i)
        indirect = &(*indirect)->next;

    // simply remove the element and free memory
    struct elem_t *free_ptr = *indirect;
    *indirect = (*indirect)->next;
    free (free_ptr);
}

/** Removes the last element */
void
popb_v (vec_t *vec)
{
    if (vec->size == 0) {
        perror ("[ \033[1;31mFAILED\033[0m ] popb_v: cannot remove elements "
                "in an empty vector");
        return;
    }

    // get iterator to the last element
    struct elem_t *p_rm = iter_begin (vec, vec->size - 1);

    free (p_rm);

    --(vec->size);
}

/** Removes the first element */
void
popf_v (vec_t *vec)
{
    if (vec->size == 0) {
        perror ("[ \033[1;31mFAILED\033[0m ] popf_v: cannot remove elements "
                "in an empty vector");
        return;
    }

    // set the front equal to the next element
    struct elem_t *p_rm = vec->front;
    vec->front = vec->front->next;

    free (p_rm);

    --(vec->size);
}
