 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * func_qualoflife.c                                                   
 *                                                                 
 * PURPOSE: 
 * Includes functions that improve the user experience.
 *
 * EXTERNAL REFERENCES:
 * 'size_t' type            (from <stdlib.h>)
 * 'printf' function        (from <stdio.h>)
 * 'LLONG_MAX' value        (from <limits.h>)
 * 'Vec' struct             (from "structs.h")
 * 'Elem' struct            (from "structs.h")
 * 'iter_begin' function    (from "devhelper.h")
 *
 * NOTES:
 * Such functions do not exist for C++ vectors.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <limits.h>
#include "vector.h"
#include "devhelper.h"
#include "structs.h"

typedef long long llong;

// prints the vector in a certain range of [beg, end)
// format: [ 0 , 1 , 2 , 3 ]
void print_v(Vec *vec, size_t beg, size_t end){
    Elem *iter = iter_begin(vec, beg);

    printf("[ ");
    for(size_t i = beg; i < end; ++i){
        if(i != end - 1) printf("%d , ", iter->data);
        else printf("%d", iter->data);
        iter = iter->next;
    }
    printf(" ]\n");
}

// gets the sum of the elements of a vector in a certain range, returns 0 if it exceeds limit
llong sum_v(Vec *vec, size_t beg, size_t end){
    Elem *iter = iter_begin(vec, beg);
    
    llong sum = 0;
    for(size_t i = beg; i < end; ++i){
        if(LLONG_MAX - iter->data <= sum) return 0;  // exceeds limit
        sum += iter->data;
        iter = iter->next;
    }
    return sum;
}

// gets the product of the elements of a vector in a certain range, returns 0 if it exceeds limit
llong prod_v(Vec *vec, size_t beg, size_t end){
    Elem *iter = iter_begin(vec, beg);

    llong prod = 1;
    for(size_t i = beg; i < end; ++i){
        if(iter->data == 0) return 0;  // if there is a 0 anywhere in range the product will always be 0
        if(LLONG_MAX / iter->data <= prod) return 0;
        prod = prod * iter->data;
        iter = iter->next;
    }
    return prod;
}
