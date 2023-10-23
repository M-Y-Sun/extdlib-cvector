/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * structs.c                                                       *
 *                                                                 *
 * Includes the structs used for the vector                        *
 * Everything in this file should be used by the developer only.   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdlib.h>

// each element in a vector will be of type Elem
typedef struct Elem{
    int data;
    struct Elem *next;
}Elem;

// declaring a vector will create a new variable of type Vec. contains the size and the first element
typedef struct Vec{
    size_t size;
    Elem *front;
}Vec;

#endif
