# Extended Library: Vector in C
C++ styled dynamic array (vector) using pointers and structured like a linked list.
* Singly linked list format
* Concise naming to match the naming style of C standard library functions

For simple projects, using a dynamic array to set an array bound is much easier and memory efficient than setting a huge upper bound.
Setting an upper bound could waste tons of memory and be hard to keep track of. When developers are limited to using C, a simple dynamic array makes code simpler and take less memory.
Update 

## Compilation and Usage
1. Place the source file named "vector.c" in a desired directory (ex. ~/extdlib/c/vector.c).
2. Add -L[filepath] to your compile flags
3. Compile as normal (ex. gcc -L~/extdlib/c/ main.c -o main)

## Important
* Is only able to store integer data currently
* Some functions may be slower than a C++ vector
* Vector setup and cleanup are NOT implicitly called; they must be manually implemented.
* Because C is a procedural language, the raw data of the vector struct can be accessed. Please refrain from directly accessing members and only use the get methods

## Future Updates
* Quality of life features that C++ vectors do not have, such as printing the list, sum, product, etc...
* Ability to store data types other than integers using void pointers (May cause significant changes to code structure, function return values, function behavior, and function parameters)

### GNU General Public License (GPL) v3.0
