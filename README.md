Extended Library: Vector in C
=============================
C++ styled dynamic array (vector) using pointers and structured like a linked list.

For simple projects, using a dynamic array to set an array bound is much easier and memory efficient than setting a huge upper bound.
Setting an upper bound could waste tons of memory and be hard to keep track of.
When developers are limited to using C, a simple dynamic array makes code simpler and take less memory.
Functions are concisely named to match the naming style of C standard library functions, such as a function named ```spop_v``` compared to ```sscanf_s``` in ```<stdlib.h>```.

### Compilation
1. Place the header file named ```vector.h``` in any directory (ex. ~/extdlib/c/vector.h).
2. Add -L[filepath] to your compile flags
3. Compile as normal (ex. gcc -L~/extdlib/c/ main.c -o main)

### Usage
* See ```GUIDELINES.md``` for correct usage of project

### Features
- [X] Memory usage scales with the array size
- [X] Supports most features of a C++ vector, excluding iterators and time complexity
- [X] Quality of life features that C++ vectors do not have, such as printing the list, sum, product, etc...
- [ ] Ability to store data types other than integers using void pointers (May cause significant changes to code structure, function return values, function behavior, and function parameters)
- [ ] Speed of a C++ vector (unlikely)

### Important
* Currently is only able to store integer data
* Maximum size is SIZE_MAX
* Some functions may be slower than a C++ vector
* Reverse iteration will be especially slow because of the singly linked list format
* Vector setup and cleanup are NOT implicitly called; they must be manually implemented.
* Because C is a procedural language, the raw data of the vector struct can be accessed. Please refrain from directly accessing members and only use the get methods
