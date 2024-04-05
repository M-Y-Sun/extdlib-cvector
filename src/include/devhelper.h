/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * devhelper.helper
 *
 * PURPOSE:
 * Declares helper functions defined by 'func_helper.c'
 *
 * EXTERNAL REFERENCES:
 * 'size_t' type    (from <stdlib.h>)
 * 'vec_t' struct     (from "structs.h")
 * 'elem_t' struct    (from "structs.h")
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "structs.h"
#include <stdlib.h>

// gets the element iterator to the requested beginning of operation
struct elem_t *iter_begin (vec_t *vec, size_t beg);
