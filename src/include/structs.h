 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * structs.h                                                   
 *                                                                 
 * PURPOSE: 
 * Includes the structs used for the vector
 *
 * EXTERNAL REFERENCES:
 * 'size_t' type            (from <stdlib.h>)
 *
 * NOTES:
 * Everything in this file should be used by the developer only.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdlib.h>

// each element in a vector will be of type elem_t
typedef struct elem_t{
    int data;
    struct elem_t *next;
}elem_t;

// declaring a vector will create a new variable of type vec_t. contains the size and the first element
typedef struct vec_t{
    size_t size;
    elem_t *front;
}vec_t;

#endif
