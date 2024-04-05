/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * mand.c                                                          *
 *                                                                 *
 * Includes mandatory functions that must be run                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * mand.c
 *
 * PURPOSE:
 * Includes mandatory functions that must be run
 *
 * EXTERNAL REFERENCES:
 * 'size_t' type            (from <stdlib.h>)
 * 'free' function          (from <stdlib.h>)
 * 'vec_t' struct             (from 'structs.h')
 * 'elem_t' struct            (from 'structs.h')
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "../include/structs.h"
#include "../include/vector.h"

// mandatory functions

// initialization
void
setup_v (vec_t *vec) {
    vec->size = 0;
    vec->front = NULL;
}

// free all the memory
void
cleanup_v (vec_t *vec) {
    if (vec->size < 2) { // if it is empty (contains only a NULL element) or
                         // has only 1 element
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
}
