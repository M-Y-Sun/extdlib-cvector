 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * func_helper.c                                                   
 *                                                                 
 * PURPOSE: 
 * includes helper functions for developer convenience.            
 *
 * EXTERNAL REFERENCES:
 * 'size_t' type    (from <stdlib.h>)
 * 'Vec' struct     (from "structs.h")
 * 'Elem' struct    (from "structs.h")
 *
 * NOTES:
 * Functions in this file should only be used by the developer.    
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "vector.h"
#include "structs.h"

// gets the element iterator to the requested beginning of the operation
Elem *iter_begin(Vec *vec, size_t beg){
    Elem *iter = vec->front;
    for(size_t i = 0; i < beg; ++i){
        iter = iter->next;
    }
    return iter;
}
