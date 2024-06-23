/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:                                                                *
 * devhelper.h                                                               *
 *                                                                           *
 * PURPOSE:                                                                  *
 * Declares helper functions defined by 'helper.c'                           *
 *                                                                           *
 * EXTERNAL REFERENCES:                                                      *
 * 'size_t' type    (from <stdlib.h>)                                        *
 * 'vec_t' struct     (from "structs.h")                                     *
 * 'elem_t' struct    (from "structs.h")                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef DEVHELPER_H
#define DEVHELPER_H

#include <stdlib.h>
#include "./structs.h"

// gets the element iterator to the requested beginning of operation
struct elem_t *iter_begin (vec_t *vec, size_t beg);

#endif
