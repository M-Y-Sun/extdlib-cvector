 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * FILE NAME:
 * func_modifier.c                                                   
 *                                                                 
 * PURPOSE: 
 * Includes functions that modify the vector.
 *
 * EXTERNAL REFERENCES:
 * 'size_t' type        (from <stdlib.h>)
 * 'free' function      (from <stdlib.h>)
 * 'malloc' function    (from <stdlib.h>)
 * 'perror' function    (from <stdio.h>)
 * 'vec_t' struct         (from "structs.h")
 * 'elem_t' struct        (from "structs.h")
 *
 * NOTES:
 * Modifications may include change in size or specific elements.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef FUNC_MODIFIER_C
#define FUNC_MODIFIER_C

#include <stdio.h>
#include <limits.h>
#include "vector.h"
#include "structs.h"

// clears everything in the vector
void clear_v(vec_t *vec){
    // cleanup function
    if(vec->size < 2){
        free(vec->front);
        return;
    }
    elem_t *ptr1 = vec->front;
    elem_t *ptr2 = vec->front;
    for(size_t i = 0; i < vec->size; ++i){
        ptr1 = ptr2;
        ptr2 = ptr1->next;
        free(ptr1);
    }
    if(ptr2 == NULL) free(ptr2);

    vec->front = NULL;
}

// fills an empty vector with specified size and initializes all values to a specified value
void assign_v(vec_t *vec, size_t size, int data){
    if(size < 0 || size > SIZE_MAX){  // if size is negative or too large that it overflows the size_t limit
         perror("requested size out of bounds\n");
         return;
    }

    if(vec->front != NULL || vec->size != 0) return; // if the vector already contains elements, dont do anything
    vec->size = size;
    elem_t *new = (elem_t*)malloc(sizeof(elem_t));
    vec->front = new;
    elem_t *iter = vec->front;
    for(size_t i = 1; i < size; ++i){
        elem_t *new_next = (elem_t*)malloc(sizeof(elem_t));
        new_next->data = data;
        iter->next = new_next;
        iter = new_next;
    }
}

// resizes the vector and initializes all values to a specified value
void resize_v(vec_t *vec, size_t size, int data){
    if(size < 0 || size > SIZE_MAX){  // if size is negative or too large that it overflows the size_t limit
         perror("requested size out of bounds\n");
         return;
    }
    
    if(vec->size == size) return;  // if the requested size = current size, do nothing
    elem_t *iter = vec->front;
    if(size < vec->size){  // if the vector wants to be shrunk, delete the elements overflowing the size
        for(size_t i = 0; i < size - 1; ++i){
            iter = iter->next;
        }
        // iter is pointing to the last element
        // delete and free the elements including and after iter using the faster cleanup algorithm
        if(vec->size - size == 1) free(iter);  // if there is only 1 element to delete
        else{
            iter = iter->next;  // pointing to the first element out of bounds
            elem_t *ptr1 = iter;
            elem_t *ptr2 = iter;
            for(size_t i = 0; i < vec->size - size; ++i){
                ptr1 = ptr2;
                ptr2 = ptr1->next;
                free(ptr1);
            }
            if(ptr2 == NULL) free(ptr2);
        }
        vec->size = size;
    }else{  // if the vector wants to be enlarged, add initialized elements to the end
        for(size_t i = 0; i < vec->size - 1; ++i){
            iter = iter->next;
        }
        for(size_t i = vec->size; i < size; ++i){
            elem_t *new = (elem_t*)malloc(sizeof(elem_t));
            new->data = data;
            iter->next = new;
            iter = new;
        }
        vec->size = size;
    }
}

// adds an element to the end
void push_v(vec_t *vec, int data){
    elem_t *new = (elem_t*)malloc(sizeof(elem_t));
    if(vec->front == NULL){ // if empty
        new->data = data;
        vec->front = new;
        new->next = NULL;
    }else{ // if not empty
        // find the position
        elem_t *cur = vec->front;
        elem_t *prev = vec->front;
        for(size_t i = 0; i < vec->size; ++i){
            prev = cur;
            cur = cur->next;
        }

        // set the values
        cur = new;
        cur->data = data;
        prev->next = cur;
    }
    ++(vec->size);
}

// changes the value of an element at a specified position
void set_v(vec_t *vec, size_t pos, int data){
    if(pos < 0 || pos >= vec->size){  // if position is negative or larger than the vector size handle the out of bounds error
        perror("requested size out of bounds\n");
        return;
    }

    elem_t *iter = vec->front;
    for(size_t i = 0; i < pos; ++i){
        iter = iter->next;
    }
    iter->data = data;
}

// inserts an element in a specified position
elem_t *insert_v(vec_t *vec, size_t pos, int data){
    if(pos < 0 || pos >= vec->size){  // if position is negative or larger than the vector size handle the out of bounds error
        perror("requested size out of bounds\n");
        return NULL;
    }

    // get to insertion position
    elem_t *iter = vec->front;
    for(size_t i = 0; i < pos-1; ++i){
        iter = iter->next;
    }

    // set the values and link
    elem_t *new = (elem_t*)malloc(sizeof(elem_t));
    new->data = data;
    new->next = iter->next;
    iter->next = new;

    return new;
}

// swaps the value of two elements in a specified position
void swap_v(vec_t *vec, size_t i1, size_t i2){
    if(i1 < 0 || i2 < 0 || i1 >= vec->size || i2 >= vec->size){  // if any requested index is negative or greater than the size, handle the out of bounds error
        perror("requested size out of bounds\n");
        return;
    }

    // make i1 always smaller than i2
    if(i1 > i2){
        int tmp = i1;
        i1 = i2;
        i2 = tmp;
    }

    // read the data
    elem_t *iter = iter_begin(vec, i1);  // get to the first index and read value

    int data1 = iter->data;
    for(size_t i = i1; i < i2; ++i){
        iter = iter->next;
    }
    int data2 = iter->data;

    // set the data
    iter = iter_begin(vec, i1);  // get to the first index and change to the swapped value

    iter->data = data2;
    for(size_t i = i1; i < i2; ++i){
        iter = iter->next;
    }
    iter->data = data1;
}

// deletes an elemtent in a specified position
void erase_v(vec_t *vec, size_t pos){
    if(pos < 0 || pos >= vec->size){  // if position is negative or larger than the vector size handle the out of bounds error
        perror("requested size out of bounds\n");
        return;
    }

    elem_t *cur = vec->front;
    elem_t *prev = vec->front;
    for(size_t i = 0; i < pos; ++i){
        prev = cur;
        cur = cur->next;
    }
    if(cur == vec->front){  // if the element to erase is the first element
        vec->front = cur->next;
    }else{  // if it is not the first element
        prev->next = cur->next;
        free(cur);
    }
}

// removes the last element; stack pop
void spop_v(vec_t *vec){
     if(vec->size == 0){
         perror("cannot remove elements in an empty vector");
         return;
     }

    elem_t *rm = iter_begin(vec, vec->size - 1);  // get iterator to the last element
    free(rm);
    --(vec->size);
}

// removes the first element; queue pop
void qpop_v(vec_t *vec){
     if(vec->size == 0){
         perror("cannot remove elements in an empty vector");
         return;
     }

    elem_t *rm = vec->front;
    vec->front = vec->front->next;  // set the front equal to the next element
    free(rm);
    --(vec->size);
}

#endif
