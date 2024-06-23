/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:                                                                *
 * helper.c                                                                  *
 *                                                                           *
 * PURPOSE:                                                                  *
 * includes helper functions for developer convenience.                      *
 *                                                                           *
 * EXTERNAL REFERENCES:                                                      *
 * 'size_t' type        (from <stdlib.h>)                                    *
 * 'perror' function    (from <stdio.h>)                                     *
 * 'vec_t' struct         (from "structs.h")                                 *
 * 'elem_t' struct        (from "structs.h")                                 *
 *                                                                           *
 * NOTES:                                                                    *
 * Functions in this file should only be used by the developer.              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include "../include/structs.h"
#include "../include/vector.h"

// gets the element iterator to the requested beginning of the operation
struct elem_t *
iter_begin (vec_t *vec, size_t beg)
{
    if (beg >= vec->size) {
        perror ("[ \033[1;31mFAILED\033[0m ] iter_begin: requested position "
                "out of bounds\n");
        return NULL;
    }

    struct elem_t *iter = vec->front;
    for (size_t i = 0; i < beg; ++i) {
        iter = iter->next;
    }
    return iter;
}
