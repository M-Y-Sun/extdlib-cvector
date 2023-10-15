#include <stdio.h>
#include <stdlib.h>
#include "vector.c"

int main(void){
    Vec *vector = (Vec*)malloc(sizeof(Vec));
    setup_v(vector);

    // vassign(vector, 3);

    Elem *e1 = push_v(vector, 0);
    Elem *e2 = push_v(vector, 1);
    Elem *e3 = push_v(vector,2);

    printf("size: %lu\n", size_v(vector));
    printf("0th index: %d\n", get_v(vector, 0));
    printf("1st index: %d\n", get_v(vector, 1));
    printf("2nd index: %d\n", get_v(vector, 2));

    // spop_v(vector);
    // qpop_v(vector);

    erase_v(vector, 1);
    printf("updated 1st index after erase: %d\n", get_v(vector, 1));

    insert_v(vector, 1, 4);
    printf("updated 1st index after insertion: %d\n", get_v(vector,1));

    // vclear(vector);
    // printf("cleared vector\n");

    set_v(vector, 1, 8);
    printf("updated 1st index after change: %d\n", get_v(vector,1));

    swap_v(vector, 1, 2);
    printf("updated 1st index after swap: %d\n", get_v(vector,1));

    resize_v(vector, 5, -1);
    printf("size after first resize: %lu\n", size_v(vector));

    resize_v(vector, 3, -1);
    printf("size after second resize: %lu\n", size_v(vector));

    printf("(first value, last value): (%d, %d)\n", front_v(vector), back_v(vector));

    printf("elements 0 to 1: ");
    print_v(vector, 0, 2);
    printf("final vector: ");
    print_v(vector, 0, size_v(vector));

    printf("sum of all elements: %lld\n", sum_v(vector, 0, size_v(vector)));
    printf("product of elements 1 to 2: %lld\n", prod_v(vector, 1, size_v(vector)));

    cleanup_v(vector);
    printf("cleanup finished\n");

    return 0;
}
