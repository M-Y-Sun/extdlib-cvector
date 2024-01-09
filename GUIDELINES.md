Guidelines for Usage and Committing
==================================

## Usage
* Do not directly access member variables of any struct
* Always explicitly include ```<stdio.h>```, ```<stdlib.h>```, and ```<limits.h>``` to prevent implicit declarations.
* Do not use any functions that are not listed in the <i>User Functions</i> section.

## Contributing
* Do not add features that require the user to directly access member variables of a struct or create an instance of the ```elem_t``` type
* Do not `typedef` any pointers or structs unless they are completely opaque and must be completely abstracted (like `vec_t`)
* File contents intended only for developer use only should be stated in the block comment prolog.
* Individual functions intended for developer use only should be marked as ```devonly``` in a comment above the function <u>only in the header file</u>, following the below example:
```c
// devonly
// function description
void devfunc(vec_t *vec);
```
* Function names should not include underscores other than the ```_v``` prefix
* Place functions in the correct file based on category (function implementations are located in the ```implementation``` directory): ```mandatory```, ```read only```, ```modifier```, and ```quality of life```.
* Separate each category with four new lines in ```vector.h```, separate category title with one new line, and do not leave a new line between function descriptions and function declaration, following the example below:
```c
// category name

// function description
void func(vec_t *vec);




// next category name
// ...
```
* Please use makefile to compile; includes support for `gcc` and `clang` with options as follows:
    ```
    # using GNU GCC compiler
    $ make gcc

    # using LLVM Clang
    $ make clang
    ```

## User Functions
Users of this project are restricted to certain functions in ```vector.h```, listed below:

Mandatory:
* ```setup_v()```
* ```cleanup_v()```

Read Only:
* ```size_v()```
* ```front_v()```
* ```back_v()```
* ```get_v()```
* ```empty_v()```

Modifiers:
* ```clear_v()```
* ```assign_v()```
* ```resize_v()```
* ```push_v()```
* ```set_v()```
* ```insert_v()```
* ```swap_v()```
* ```erase_v()```
* ```spop_v()```
* ```qpop_v()```

Quality of Life:
* ```print_v()```
* ```sum_v()```
* ```prod_v()```
