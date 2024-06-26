/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:                                                                *
 * qol.c                                                                     *
 *                                                                           *
 * PURPOSE:                                                                  *
 * Includes functions that improve the user experience.                      *
 *                                                                           *
 * EXTERNAL REFERENCES:                                                      *
 * 'size_t' type            (from <stdlib.h>)                                *
 * 'printf' function        (from <stdio.h>)                                 *
 * 'perror' function        (from <stdio.h>)                                 *
 * 'LLONG_MAX' value        (from <limits.h>)                                *
 * 'vec_t' struct             (from "structs.h")                             *
 * 'elem_t' struct            (from "structs.h")                             *
 * 'iter_begin' function    (from "devhelper.h")                             *
 *                                                                           *
 * NOTES:                                                                    *
 * Such functions do not exist for C++ vectors.                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <limits.h>
#include <stdio.h>
#include "../include/devhelper.h"
#include "../include/structs.h"
#include "../include/vector.h"

// prints the vector in a certain range of [beg, end)
// format: [ 0 , 1 , 2 , 3 ]
void
print_v (vec_t *vec, size_t beg, size_t end)
{
    if (beg < 0 || end < 0 || beg > vec->size || end > vec->size
        || beg > end) { // if requested size is negative, out of bounds, or
                        // beginning > end
        perror ("[ \033[1;31mFAILED\033[0m ] print_v: requested position out "
                "of bounds");
        return;
    }

    struct elem_t *iter = iter_begin (vec, beg);

    printf ("[ ");
    for (size_t i = beg; i < end; ++i) {
        if (i != end - 1)
            printf ("%d , ", iter->data);
        else
            printf ("%d", iter->data);
        iter = iter->next;
    }
    printf (" ]\n");
}

// gets the sum of the elements of a vector in a certain range, returns -1 if
// it exceeds limit
int64_t
sum_v (vec_t *vec, size_t beg, size_t end)
{
    if (beg < 0 || end < 0 || beg > vec->size || end > vec->size
        || beg > end) { // if requested size is negative, out of bounds, or
                        // beginning > end
        perror ("[ \033[1;31mFAILED\033[0m ] sum_v: requested position out of "
                "bounds");
        return 0;
    }

    struct elem_t *iter = iter_begin (vec, beg);

    int64_t sum = 0;
    for (size_t i = beg; i < end; ++i) {
        if (LLONG_MAX - iter->data <= sum)
            return -1; // exceeds limit
        sum += iter->data;
        iter = iter->next;
    }
    return sum;
}

// gets the product of the elements of a vector in a certain range, returns -1
// if it exceeds limit
int64_t
prod_v (vec_t *vec, size_t beg, size_t end)
{
    if (beg < 0 || end < 0 || beg > vec->size || end > vec->size
        || beg > end) { // if requested size is negative, out of bounds, or
                        // beginning > end
        perror ("[ \033[1;31mFAILED\033[0m ] prod_v: requested position out "
                "of bounds");
        return 0;
    }

    struct elem_t *iter = iter_begin (vec, beg);

    int64_t prod = 1;
    for (size_t i = beg; i < end; ++i) {
        if (iter->data == 0)
            return 0; // if there is a 0 anywhere in range the product will
                      // always be 0
        if (LLONG_MAX / iter->data <= prod)
            return -1; // exceeds limit
        prod = prod * iter->data;
        iter = iter->next;
    }
    return prod;
}
