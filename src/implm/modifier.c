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

#ifndef MODIFIER_C
#define MODIFIER_C

#include <stdio.h>
#include "../include/structs.h"
#include "../include/vector.h"

// clears everything in the vector
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

// fills an empty vector with specified size and initializes all values to a
// specified value
void
assign_v (vec_t *vec, size_t size, int data)
{
    // if size is negative or too large that it overflows the size limit
    if (size < 0 || size > SIZE_MAX) {
        perror ("[ \033[1;31mFAILED\033[0m ] assign_v: requested size out of "
                "bounds\n");
        return;
    }

    if (vec->front != NULL || vec->size != 0)
        // if the vector already contains elements, dont do anything
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

// resizes the vector and initializes all values to a specified value
void
resize_v (vec_t *vec, size_t size, int data)
{
    // if size is negative or too large that it overflows the size_t limit
    if (size < 0 || size > SIZE_MAX) {
        perror ("[ \033[1;31mFAILED\033[0m ] resize_v: requested size out of "
                "bounds\n");
        return;
    }

    if (vec->size == size) {
        // if the requested size = current size, do nothing
        return;
    }

    struct elem_t *iter = vec->front;

    // if the vector wants to be shrunk,
    // delete the elements overflowing the size
    if (size < vec->size) {
        for (size_t i = 0; i < size - 1; ++i) {
            iter = iter->next;
        }

        // iter is pointing to the last element
        // delete and free the elements including and after iter using the
        // faster cleanup algorithm
        if (vec->size - size == 1) {
            free (iter); // if there is only 1 element to delete
        } else {
            // iter is now pointing to the first element out of bounds
            struct elem_t *ptr1 = iter;
            struct elem_t *ptr2 = iter;
            for (size_t i = 0; i < vec->size - size; ++i) {
                ptr1 = ptr2;
                ptr2 = ptr1->next;
                free (ptr1);
            }

            if (ptr2 == NULL) {
                free (ptr2);
            }
        }

        vec->size = size;
        // if the vector wants to be enlarged,
        // add initialized elements to the add
    } else {
        for (size_t i = 0; i < vec->size - 1; ++i) {
            iter = iter->next;
        }
        for (size_t i = vec->size; i < size; ++i) {
            struct elem_t *new
                = (struct elem_t *)malloc (sizeof (struct elem_t));
            if (new == NULL) {
                perror ("[ \033[1;31mFAILED\033[0m ] malloc: "
                        "memory request "
                        "service failed\n");
                return;
            }
            new->data = data;
            iter->next = new;
            iter = new;
        }
        vec->size = size;
    }
}

// adds an element to the end
void
pushb_v (vec_t *vec, int data)
{
    struct elem_t *new = (struct elem_t *)malloc (sizeof (struct elem_t));
    if (new == NULL) {
        perror ("[ \033[1;31mFAILED\033[0m ] malloc: memory request service "
                "failed\n");
        return;
    }

    if (vec->front == NULL) { // if empty
        new->data = data;
        vec->front = new;
        new->next = NULL;
    } else { // if not empty
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

// returns a pointer to the value at a certain position
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

// inserts an element in a specified position
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

// swaps the value of two elements in a specified position
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
    struct elem_t *iter
        = iter_begin (vec, i1); // get to the first index and read value

    int data1 = iter->data;
    for (size_t i = i1; i < i2; ++i) {
        iter = iter->next;
    }

    int data2 = iter->data;

    // set the data
    iter = iter_begin (
        vec, i1); // get to the first index and change to the swapped value

    iter->data = data2;
    for (size_t i = i1; i < i2; ++i) {
        iter = iter->next;
    }

    iter->data = data1;
}

// deletes an elemtent in a specified position
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

    // indirect pointer points to the address of the element to be removed
    struct elem_t **indirect = &vec->front;
    for (size_t i = 0; i < pos; ++i) {
        indirect = &(*indirect)->next;
    }

    // simply remove the element and free memory
    struct elem_t *free_ptr = *indirect;
    *indirect = (*indirect)->next;
    free (free_ptr);
}

// removes the last element
void
popb_v (vec_t *vec)
{
    if (vec->size == 0) {
        perror ("[ \033[1;31mFAILED\033[0m ] popb_v: cannot remove elements "
                "in an empty vector");
        return;
    }

    struct elem_t *rm
        = iter_begin (vec, vec->size - 1); // get iterator to the last element
    free (rm);
    --(vec->size);
}

// removes the first element
void
popf_v (vec_t *vec)
{
    if (vec->size == 0) {
        perror ("[ \033[1;31mFAILED\033[0m ] popf_v: cannot remove elements "
                "in an empty vector");
        return;
    }

    struct elem_t *rm = vec->front;
    vec->front = vec->front->next; // set the front equal to the next element
    free (rm);
    --(vec->size);
}

#endif
