/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:                                                                *
 * readonly.c                                                                *
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
 * vector will be unchanged after funcion call.                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>

#include "structs.h"
#include "vector.h"

/** @return The length of the vector */
size_t
size_v (vec_t *vec)
{
    return vec->size;
}

/** @return A pointer to the first value */
int
front_v (vec_t *vec)
{
    return vec->front->data;
}

/** @return A pointer to the last value */
int
back_v (vec_t *vec)
{
    struct elem_t *iter = vec->front;

    for (size_t i = 0; i < vec->size - 1; ++i)
        iter = iter->next;

    return iter->data;
}

/** @return If the vector is empty */
int
empty_v (vec_t *vec)
{
    return vec->front == NULL;
}
