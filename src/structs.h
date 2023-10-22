// everything in this file is devonly

#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdlib.h>

typedef long long llong;

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
