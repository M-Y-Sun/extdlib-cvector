 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * vector.h                                                   
 *                                                                 
 * PURPOSE: 
 * Includes function declarations/prototypes for all functions
 *
 * EXTERNAL REFERENCES:
 * 'size_t' type            (from <stdlib.h>)
 * 'Vec' struct             (from 'structs.h')
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef VECTOR_H
#define VECTOR_H

// Vec struct and Elem struct
#include "structs.h"

typedef long long llong;

// helper function; devonly
// gets the element iterator to the requested beginning of the operation
Elem *iter_begin(Vec *vec, size_t beg);


// must include

// initialization
void setup_v(Vec *vec);

// free all the memory
void cleanup_v(Vec *vec);




// read only functions

// returns the length of the vector
size_t size_v(Vec *vec);

// returns the first value
int front_v(Vec *vec);

// returns the last value
int back_v(Vec *vec);

// gets the value at a certain position
int get_v(Vec *vec, size_t pos);

// checks if the vector is empty (1 = true; 0 = false)
int empty_v(Vec *vec);




//modifier functions

// clears everything in the vector
void clear_v(Vec *vec);

// fills an empty vector with specified size and initializes all values to a specified value
void assign_v(Vec *vec, size_t size, int data);

// resizes the vector and initializes all values to a specified value
void resize_v(Vec *vec, size_t size, int data);

// adds an element to the end
void push_v(Vec *vec, int data);

// changes the value of an element at a specified position
void set_v(Vec *vec, size_t pos, int data);

// inserts an element in a specified position
Elem *insert_v(Vec *vec, size_t pos, int data);

// swaps the value of two elements in a specified position
void swap_v(Vec *vec, size_t i1, size_t i2);

// deletes an elemtent in a specified position
void erase_v(Vec *vec, size_t pos);

// removes the last element; stack pop
void spop_v(Vec *vec);

// removes the first element; queue pop
void qpop_v(Vec *vec);




// quality of life functions (read only)

// prints the vector in a certain range of [beg, end)
// format: [ 0 , 1 , 2 , 3 ]
void print_v(Vec *vec, size_t beg, size_t end);

// gets the sum of the elements of a vector in a certain range, returns 0 if it exceeds limit
llong sum_v(Vec *vec, size_t beg, size_t end);

// gets the product of the elements of a vector in a certain range, returns 0 if it exceeds limit
llong prod_v(Vec *vec, size_t beg, size_t end);

#endif
