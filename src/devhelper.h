 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * devhelper.helper                                                   
 *                                                                 
 * PURPOSE: 
 * Declares helper functions defined by 'func_helper.c'
 *
 * EXTERNAL REFERENCES:
 * 'size_t' type    (from <stdlib.h>)
 * 'Vec' struct     (from "structs.h")
 * 'Elem' struct    (from "structs.h")
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

 #include <stdlib.h>
 #include "structs.h"

// gets the element iterator to the requested beginning of operation
Elem *iter_begin(Vec *vec, size_t beg);
