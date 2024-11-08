/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:                                                                *
 * vector.h                                                                  *
 *                                                                           *
 * PURPOSE:                                                                  *
 * Includes function declarations/prototypes for all functions               *
 *                                                                           *
 * EXTERNAL REFERENCES:                                                      *
 * 'size_t' type            (from <stdlib.h>)                                *
 * 'elem_t' struct          (from 'structs.h')                               *
 * 'vec_t' struct           (from 'structs.h')                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

#include "./structs.h"

/****** MUST INCLUDE ******/

/** Initializes a `vec_t` instance. */
void setup_v (vec_t *vec);

/** Cleans up a `vec_t` instance to free allocated memory. */
void cleanup_v (vec_t *vec);

/****** READ ONLY FUNCTIONS ******/

/** @return The length of the vector */
size_t size_v (vec_t *vec);

/** @return A pointer to the first value */
int front_v (vec_t *vec);

/** @return A pointer to the last value */
int back_v (vec_t *vec);

/** @return If the vector is empty */
int empty_v (vec_t *vec);

/****** MODIFIER FUNCTIONS ******/

/** Deletes all elements in the vector. */
void clear_v (vec_t *vec);

/**
 * Fills an empty vector to a specified size and initializes all values to a
 * specified value
 * @param size The size to assign to
 * @param data The data to assign each element to
 * */
void assign_v (vec_t *vec, size_t size, int data);

/**
 * Resizes the vector and initiates all values to a specific value
 * @param size The size to resize to
 * @param data The data to assign each new value to
 * */
void resize_v (vec_t *vec, size_t size, int data);

/**
 * Adds an element to the end
 * @param data The data to append
 * */
void pushb_v (vec_t *vec, int data);

/**
 * @param pos The position to get
 * @return A pointer to the value at a certain location.
 * */
int *get_v (vec_t *vec, size_t pos);

/**
 * Inserts an element in a specified position
 * @param pos The position to insert at
 * @param data The data to insert
 * */
struct elem_t *insert_v (vec_t *vec, size_t pos, int data);

/**
 * Swaps the value of two elements in a specified position
 * @param i1 The index of the first element
 * @param i2 The index of the second element
 * */
void swap_v (vec_t *vec, size_t i1, size_t i2);

/**
 * Deletes an element in a specified position
 * @param pos The position to erase
 * */
void erase_v (vec_t *vec, size_t pos);

/** Removes the last element */
void popb_v (vec_t *vec);

/** Removes the first element */
void popf_v (vec_t *vec);

/****** QUALITY OF LIFE FUNCTIONS (READ ONLY) ******/

/**
 * Prints the vector in a certain range specified by [beg, end)
 *
 * Print format: '[ 0 , 1 , 2 , 3 ]'
 *
 * @param beg The beginning index
 * @param end The ending index
 * */
void print_v (vec_t *vec, size_t beg, size_t end);

/**
 * @return The sum of the elements of a vector in a certain range [beg, end).
 * @param beg The beginning index
 * @param end The ending index
 * */
int64_t sum_v (vec_t *vec, size_t beg, size_t end);

/**
 * @return The product of the elements of a vector in a certain range
 * @param beg The beginning index
 * @param end The ending index
 * */
int64_t prod_v (vec_t *vec, size_t beg, size_t end);
