Guidelines for Usage and Committing
==================================

## Usage
* Do not directly access member variables of any struct
* Do not use the ```llong``` typedef defined in ```vector.h``` to prevent implicit declarations. Declare again explicitly if needed.
* Always explicitly include ```<stdio.h>```, ```<stdlib.h>```, and ```<limits.h>``` to prevent implicit declarations.
* Do not use any functions that are not listed in the <i>User Functions</i> section.

## Committing
* Do not add features that require the user to directly access member variables of a struct or create an instance of the ```Elem``` type
* Always mark functions intended for developer use only as ```devonly``` in a comment above the function <u>only in the header file</u>, following the below example:
```c
// devonly
// function description
void devfunc(Vec *vec);
```
* Function names should not include underscores other than the ```_v``` prefix
* Place functions in the correct file based on category: ```mandatory```, ```read only```, ```modifier```, and ```quality of life```
* Separate each category with four new lines in ```vector.h```, separate category title with one new line, and do not leave a new line between function descriptions and function declaration, following the example below:
```c
// category name

// function description
void func(Vec *vec);




// next category name
// ...
```

## User Functions
Users of this project are restricted to certain functions in ```vector.h```, listed below:

Must Include:
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
