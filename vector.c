#ifndef VECTOR_C
#define VECTOR_C

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// devonly
typedef long long llong;

// devonly
// each element in a vector will be of type Elem
typedef struct Elem{
    int data;
    struct Elem *next;
}Elem;

// declaring a vector will create a new variable of type Vec. contains the size and the first element
typedef struct Vec{
    size_t size;
    Elem *front;
}Vec;

// helper function; devonly
// gets the element iterator to the requested beginning of the operation
Elem *iter_begin(Vec *vec, size_t beg){
    Elem *iter = vec->front;
    for(size_t i = 0; i < beg; ++i){
        iter = iter->next;
    }
    return iter;
}


// must include

// initialization
void setup_v(Vec *vec){
    vec->size = 0;
    vec->front = NULL;
}

// free all the memory
void cleanup_v(Vec *vec){
    if(vec->size < 2){  // if it is empty (contains only a NULL element) or has only 1 element
        free(vec->front);
        return;
    }
    Elem *ptr1 = vec->front;
    Elem *ptr2 = vec->front;
    for(size_t i = 0; i < vec->size; ++i){
        ptr1 = ptr2;
        ptr2 = ptr1->next;
        free(ptr1);
    }
    if(ptr2 == NULL) free(ptr2);
}




// read only functions

// returns the length of the vector
size_t size_v(Vec *vec){return vec->size;}

// returns the first value
int front_v(Vec *vec){return vec->front->data;}

// returns the last value
int back_v(Vec *vec){
    Elem *iter = vec->front;
    for(size_t i = 0; i < vec->size - 1; ++i){
        iter = iter->next;
    }
    return iter->data;
}

// gets the value at a certain position
int get_v(Vec *vec, size_t pos){
    Elem *iter = vec->front;
    for(size_t i = 0; i < pos; ++i){
        iter = iter->next;
    }
    int data = iter->data;
    return data;
}

// checks if the vector is empty (1 = true; 0 = false)
int empty_v(Vec *vec){
    if(vec->front == NULL) return 1;
    return 0;
}




//modifier functions

// clears everything in the vector
void clear_v(Vec *vec){
    cleanup_v(vec);
    vec->front = NULL;
}

// fills an empty vector with specified size and initializes all values to a specified value
void assign_v(Vec *vec, size_t size, int data){
    if(vec->front != NULL || vec->size != 0) return; // if the vector already contains elements, dont do anything
    vec->size = size;
    Elem *new = (Elem*)malloc(sizeof(Elem));
    vec->front = new;
    Elem *iter = vec->front;
    for(size_t i = 1; i < size; ++i){
        Elem *new_next = (Elem*)malloc(sizeof(Elem));
        new_next->data = data;
        iter->next = new_next;
        iter = new_next;
    }
}

// resizes the vector and initializes all values to a specified value
void resize_v(Vec *vec, size_t size, int data){
    if(vec->size == size) return;  // if the requested size = current size, do nothing
    Elem *iter = vec->front;
    if(size < vec->size){  // if the vector wants to be shrunk, delete the elements overflowing the size
        for(size_t i = 0; i < size - 1; ++i){
            iter = iter->next;
        }
        // iter is pointing to the last element
        // delete and free the elements including and after iter using the faster cleanup algorithm
        if(vec->size - size == 1) free(iter);  // if there is only 1 element to delete
        else{
            iter = iter->next;  // pointing to the first element out of bounds
            Elem *ptr1 = iter;
            Elem *ptr2 = iter;
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
            Elem *new = (Elem*)malloc(sizeof(Elem));
            new->data = data;
            iter->next = new;
            iter = new;
        }
        vec->size = size;
    }
}

// adds an element to the end
Elem *push_v(Vec *vec, int data){
    Elem *new = (Elem*)malloc(sizeof(Elem));
    if(vec->front == NULL){ // if empty
        new->data = data;
        vec->front = new;
        new->next = NULL;
    }else{ // if not empty
        // find the position
        Elem *cur = vec->front;
        Elem *prev = vec->front;
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

    return new;
}

// changes the value of an element at a specified position
void set_v(Vec *vec, size_t pos, int data){
    Elem *iter = vec->front;
    for(size_t i = 0; i < pos; ++i){
        iter = iter->next;
    }
    iter->data = data;
}

// inserts an element in a specified position
Elem *insert_v(Vec *vec, size_t pos, int data){
    // get to insertion position
    Elem *iter = vec->front;
    for(size_t i = 0; i < pos-1; ++i){
        iter = iter->next;
    }

    // set the values and link
    Elem *new = (Elem*)malloc(sizeof(Elem));
    new->data = data;
    new->next = iter->next;
    iter->next = new;

    return new;
}

// swaps the value of two elements in a specified position
void swap_v(Vec *vec, size_t i1, size_t i2){
    // make i1 always smaller than i2
    if(i1 > i2){
        int tmp = i1;
        i1 = i2;
        i2 = tmp;
    }

    // read the data
    Elem *iter = vec->front;
    for(size_t i = 0; i < i1; ++i){
        iter = iter->next;
    }
    int data1 = iter->data;
    for(size_t i = i1; i < i2; ++i){
        iter = iter->next;
    }
    int data2 = iter->data;

    // set the data
    iter = vec->front;
    for(size_t i = 0; i < i1; ++i){
        iter = iter->next;
    }
    iter->data = data2;
    for(size_t i = i1; i < i2; ++i){
        iter = iter->next;
    }
    iter->data = data1;
}

// deletes an elemtent in a specified position
void erase_v(Vec *vec, size_t pos){
    Elem *cur = vec->front;
    Elem *prev = vec->front;
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
void spop_v(Vec *vec){
    Elem *iter = vec->front;
    for(size_t i = 0; i < vec->size - 1; ++i){
        iter = iter->next;
    }
    free(iter);
    --(vec->size);
}

// removes the first element; queue pop
void qpop_v(Vec *vec){  // check if this works properly with debugger
    Elem *rm = vec->front;
    vec->front = vec->front->next;
    free(rm);
    --(vec->size);
}




// quality of life functions (read only)

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

#endif
