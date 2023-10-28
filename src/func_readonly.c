 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * func_readonly.c                                                   
 *                                                                 
 * PURPOSE: 
 * Includes functions that obtain data from the vector.
 *
 * EXTERNAL REFERENCES:
 * 'size_t' type            (from <stdlib.h>)
 * 'Vec' struct             (from "structs.h")
 * 'Elem' struct            (from "structs.h")
 *
 * NOTES:
 * Vector will be unchanged after funcion call.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef FUNC_READONLY_C
#define FUNC_READONLY_C

#include "vector.h"
#include "structs.h"

// returns the length of the vector
size_t size_v(Vec *vec){return vec->size;}

// returns the first value
int front_v(Vec *vec){return vec->front->data;}

// returns the last value
int back_v(Vec *vec){
    Elem *iter = vec->front;
    for(size_t i = 0; i < vec->size - 1; ++i){
        iter = iter->next;
    }
    return iter->data;
}

// gets the value at a certain position
int get_v(Vec *vec, size_t pos){
    Elem *iter = vec->front;
    for(size_t i = 0; i < pos; ++i){
        iter = iter->next;
    }
    int data = iter->data;
    return data;
}

// checks if the vector is empty (1 = true; 0 = false)
int empty_v(Vec *vec){
    if(vec->front == NULL) return 1;
    return 0;
}

#endif
