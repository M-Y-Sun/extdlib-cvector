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

#include "devhelper.h"
#include "structs.h"
#include "vector.h"

/**
 * Checks if the specified beginning and ending index is within the bounds of
 * the vector.
 * @param beg The beginning index
 * @param end The ending index
 */
static inline int
inbound_v_ (vec_t *vec, size_t beg, size_t end)
{
    return beg < 0 || end < 0 || beg > vec->size || end > vec->size
           || beg > end;
}

/**
 * Prints the vector in a certain range specified by [beg, end)
 *
 * Print format: '[ 0 , 1 , 2 , 3 ]'
 *
 * @param beg The beginning index
 * @param end The ending index
 * */
void
print_v (vec_t *vec, size_t beg, size_t end)
{
    if (inbound_v_ (vec, beg, end)) {
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

/**
 * @return The sum of the elements of a vector in a certain range [beg, end).
 * @param beg The beginning index
 * @param end The ending index
 * */
int64_t
sum_v (vec_t *vec, size_t beg, size_t end)
{
    if (inbound_v_ (vec, beg, end)) {
        perror ("[ \033[1;31mFAILED\033[0m ] sum_v: requested position out of "
                "bounds");
        return 0;
    }

    struct elem_t *iter = iter_begin (vec, beg);
    int64_t sum = 0;

    for (size_t i = beg; i < end; ++i) {
        sum += iter->data;
        iter = iter->next;
    }

    return sum;
}

/**
 * @return The product of the elements of a vector in a certain range
 * @param beg The beginning index
 * @param end The ending index
 * */
int64_t
prod_v (vec_t *vec, size_t beg, size_t end)
{
    if (inbound_v_ (vec, beg, end)) {
        perror ("[ \033[1;31mFAILED\033[0m ] prod_v: requested position out "
                "of bounds");
        return 0;
    }

    struct elem_t *iter = iter_begin (vec, beg);
    int64_t prod = 1;

    for (size_t i = beg; i < end; ++i) {
        if (iter->data == 0)
            return 0;

        prod = prod * iter->data;
        iter = iter->next;
    }

    return prod;
}
