/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * main.c
 *
 * PURPOSE:
 * Demonstration for all available functions.
 *
 * EXTERNAL REFERENCES:
 * all functions declared in "vector.h"
 * 'printf' function        (from <stdio.h>)
 * 'malloc' function        (from <stdlib.h>)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "include/vector.h"
#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
    vec_t *vector = (vec_t *)malloc (sizeof (vec_t));
    setup_v (vector); // set up the vector
    printf ("[   \033[1;32mOK\033[0m   ] setup finished\n");

    // vassign(vector, 3);  <- sets the vector to size 3 with values of 0. Only
    // works when vector is empty

    // append 3 values to the vector
    push_v (vector, 0);
    push_v (vector, 1);
    push_v (vector, 2);

    // print information
    // size_v() gets the size of the vector
    printf ("size: %lu\n", size_v (vector));
    // get_v gets the address of the value at a specific position
    printf ("0th index: %d\n", *get_v (vector, 0));
    printf ("1st index: %d\n", *get_v (vector, 1));
    printf ("2nd index: %d\n", *get_v (vector, 2));

    // spop_v(vector);  <- deletes the last value like a stack
    // qpop_v(vector);  <- deletes the first value like a queue

    erase_v (vector, 1); // erases the element at a certain index
    printf ("updated 1st index after erase: %d\n", *get_v (vector, 1));

    // inserts an element at a certain index with a certain value
    insert_v (vector, 1, 4);
    printf ("updated 1st index after insertion: %d\n", *get_v (vector, 1));

    // vclear(vector);  // deletes all elements

    *get_v (vector, 1) = 8;
    printf ("updated 1st index after change: %d\n", *get_v (vector, 1));

    swap_v (vector, 1, 2); // swaps two elements
    printf ("updated 1st index after swap: %d\n", *get_v (vector, 1));

    resize_v (vector, 5, -1); // resizes the vector to a certain size with
                              // undefined values set to a certain value
    printf ("size after first resize: %lu\n", size_v (vector));

    resize_v (vector, 3, -1);
    printf ("size after second resize: %lu\n", size_v (vector));

    printf ("(first value, last value): (%d, %d)\n", front_v (vector),
            back_v (vector)); // gets the first and last value respectively

    printf ("elements 0 to 1: ");
    print_v (vector, 0, 2);
    printf ("final vector: ");
    print_v (vector, 0, size_v (vector));
    // computes the sum of the elements in a certain range, returns int64_t
    printf ("sum of all elements: %lld\n", sum_v (vector, 0, size_v (vector)));

    // computes the product of all the elements in a certain range, returns
    // int64_t
    printf ("product of elements 1 to 2: %lld\n",
            prod_v (vector, 1, size_v (vector)));

    cleanup_v (vector); // clean up vector and free memory
    printf ("[   \033[1;32mOK\033[0m   ] cleanup finished\n");

    return 0;
}
