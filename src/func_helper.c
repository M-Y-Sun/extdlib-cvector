#ifndef FUNC_HELPER_C
#define FUNC_HELPER_C

#include "vector.h"
#include "structs.h"

// helper function
// gets the element iterator to the requested beginning of the operation
Elem *iter_begin(Vec *vec, size_t beg){
    Elem *iter = vec->front;
    for(size_t i = 0; i < beg; ++i){
        iter = iter->next;
    }
    return iter;
}

#endif
