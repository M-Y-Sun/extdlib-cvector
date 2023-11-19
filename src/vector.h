 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * vector.h                                                   
 *                                                                 
 * PURPOSE: 
 * Includes function declarations/prototypes for all functions
 *
 * EXTERNAL REFERENCES:
 * 'size_t' type            (from <stdlib.h>)
 * 'vec_t' struct             (from 'structs.h')
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef VECTOR_H
#define VECTOR_H

// vec_t struct and elem_t struct
#include "structs.h"

typedef long long llong;

// helper function; devonly
// gets the element iterator to the requested beginning of the operation
elem_t *iter_begin(vec_t *vec, size_t beg);


// must include

// initialization
void setup_v(vec_t *vec);

// free all the memory
void cleanup_v(vec_t *vec);




// read only functions

// returns the length of the vector
size_t size_v(vec_t *vec);

// returns the first value
int front_v(vec_t *vec);

// returns the last value
int back_v(vec_t *vec);

// checks if the vector is empty (1 = true; 0 = false)
int empty_v(vec_t *vec);




//modifier functions

// clears everything in the vector
void clear_v(vec_t *vec);

// fills an empty vector with specified size and initializes all values to a specified value
void assign_v(vec_t *vec, size_t size, int data);

// resizes the vector and initializes all values to a specified value
void resize_v(vec_t *vec, size_t size, int data);

// adds an element to the end
void push_v(vec_t *vec, int data);

// returns a pointer to the value at a certain position
int *get_v(vec_t *vec, size_t pos);

// inserts an element in a specified position
elem_t *insert_v(vec_t *vec, size_t pos, int data);

// swaps the value of two elements in a specified position
void swap_v(vec_t *vec, size_t i1, size_t i2);

// deletes an elemtent in a specified position
void erase_v(vec_t *vec, size_t pos);

// removes the last element; stack pop
void spop_v(vec_t *vec);

// removes the first element; queue pop
void qpop_v(vec_t *vec);




// quality of life functions (read only)

// prints the vector in a certain range of [beg, end)
// format: [ 0 , 1 , 2 , 3 ]
void print_v(vec_t *vec, size_t beg, size_t end);

// gets the sum of the elements of a vector in a certain range, returns 0 if it exceeds limit
llong sum_v(vec_t *vec, size_t beg, size_t end);

// gets the product of the elements of a vector in a certain range, returns 0 if it exceeds limit
llong prod_v(vec_t *vec, size_t beg, size_t end);

#endif
