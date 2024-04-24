/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:                                                                *
 * func_readonly.c                                                           *
 *                                                                           *
 * PURPOSE:                                                                  *
 * Includes functions that obtain data from the vector.                      *
 *                                                                           *
 * EXTERNAL REFERENCES:                                                      *
 * 'size_t' type            (from <stdlib.h>)                                *
 * 'perror' function        (from <stdio.h>)                                 *
 * 'vec_t' struct             (from "structs.h")                             *
 * 'elem_t' struct            (from "structs.h")                             *
 *                                                                           *
 * NOTES:                                                                    *
 * vec_ttor will be unchanged after funcion call.                            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef FUNC_READONLY_C
#define FUNC_READONLY_C

#include "../include/structs.h"
#include "../include/vector.h"
#include <stdio.h>

// returns the length of the vector
size_t
size_v (vec_t *vec)
{
    return vec->size;
}

// returns the first value
int
front_v (vec_t *vec)
{
    return vec->front->data;
}

// returns the last value
int
back_v (vec_t *vec)
{
    struct elem_t *iter = vec->front;
    for (size_t i = 0; i < vec->size - 1; ++i) {
        iter = iter->next;
    }
    return iter->data;
}

// checks if the vector is empty (1 = true; 0 = false)
int
empty_v (vec_t *vec)
{
    if (vec->front == NULL)
        return 1;
    return 0;
}

#endif
