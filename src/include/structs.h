/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:                                                                *
 * structs.h                                                                 *
 *                                                                           *
 * PURPOSE:                                                                  *
 * Includes the structs used for the vector                                  *
 *                                                                           *
 * EXTERNAL REFERENCES:                                                      *
 * 'size_t' type            (from <stdlib.h>)                                *
 *                                                                           *
 * NOTES:                                                                    *
 * Everything in this file should be used by the developer only.             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

#include <stdlib.h>

/** A single element in a vector */
struct elem_t {
    int data;
    struct elem_t *next;
};

/** The vector type representing the beginning of the data structure. */
typedef struct {
    size_t size;
    struct elem_t *front;
} vec_t;
