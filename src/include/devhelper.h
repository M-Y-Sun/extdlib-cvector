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

#pragma once

#include <stdlib.h>
#include "./structs.h"

/**
 * Helper function; DEVONLY
 *
 * @return An element iterator to the requested beginning of the operation.
 * @param vec The vector to operate on.
 * @param beg The index to begin at
 * */
struct elem_t *iter_begin (vec_t *vec, size_t beg);
