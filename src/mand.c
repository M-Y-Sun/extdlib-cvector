/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * mand.c                                                          *
 *                                                                 *
 * Includes mandatory functions that must be run                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MAND_C
#define MAND_C

#include "vector.h"
#include "structs.h"

// mandatory functions

// initialization
void setup_v(Vec *vec){
    vec->size = 0;
    vec->front = NULL;
}

// free all the memory
void cleanup_v(Vec *vec){
    if(vec->size < 2){  // if it is empty (contains only a NULL element) or has only 1 element
        free(vec->front);
        return;
    }
    Elem *ptr1 = vec->front;
    Elem *ptr2 = vec->front;
    for(size_t i = 0; i < vec->size; ++i){
        ptr1 = ptr2;
        ptr2 = ptr1->next;
        free(ptr1);
    }
    if(ptr2 == NULL) free(ptr2);
}

#endif
