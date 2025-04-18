# Extended Library: Vector in C

**Notice: This repository has been archived and has been migrated to https://github.com/s7a19t4r/c-dsa**

C++ styled dynamic array (vector) as a linked list, written in C.

For simple projects, using a dynamic array to set an array bound is much easier and memory efficient than setting a huge upper bound.
Setting an upper bound could waste tons of memory and be hard to keep track of.
When developers are limited to using C, a simple dynamic array makes code simpler and take less memory.
Functions are concisely named to match the naming style of C standard library functions, such as a function named `pushb_v` compared to `sscanf_s` in `<stdlib.h>`.

### Usage

1. Create a directory to store the source files (ex. `~/.extdlib/c/`)
2. `cd` to the file (ex `cd ~/.extdlib/c/`)
3. Clone this repository into the directory:
    ```
    $ git clone https://github.com/s7a19t4r/extdlib-cvector
    ```
4. Place the header file named `vector.h` in a directory (ex. ~/.extdlib/c/vector.h).
5. Add `-L[filepath]` to your compile flags (ex. `-L~/.extdlib/c/extdlib-cvector/src/`).
6. Compile your source file as normal (ex. `gcc -L~/.extdlib/c/extdlib-cvector/src/ main.c -o main.elf`)

See `GUIDELINES.md` for correct usage of project

### Contributing

##### Clone the Repository

`cd` to a directory and clone:

```
$ git clone https://github.com/s7a19t4r/extdlib-cvector
```

See `GUIDELINES.md` for contribution guidelines

##### Install `gcc` Compiler

<details>
<summary>Debian/Windows (WSL2)</summary>

```
$ sudo apt install gcc
```

</details>

<details>
<summary>Arch</summary>

```
$ sudo pacman -S gcc
```

</details>

<details>
<summary>Fedora</summary>

```
$ sudo dnf install gcc
```

</details>

<details>
<summary>macOS (installs LLVM Clang)</summary>

```
$ brew install llvm
```

</details>

##### Install ClangFormat (config provided)

<details>
<summary>Debian/Windows (WSL2)</summary>

```
$ sudo apt install clang-format
```

</details>

<details>
<summary>Arch</summary>

```
$ sudo pacman -S clang-format
```

</details>

<details>
<summary>Fedora</summary>

```
$ sudo dnf install clang-tools-extra
```

</details>

<details>
<summary>macOS</summary>

```
$ brew install clang-format
```

</details>

### Important

- Currently is only able to store integer data
- Maximum size is `SIZE_MAX`
- Some functions may be slower than a C++ vector
- Reverse iteration will be especially slow because of the singly linked list format
- Vector setup and cleanup are NOT implicitly called; they must be manually implemented.
- Because C is a procedural language, the raw data of the vector struct can be accessed. Please refrain from directly accessing members and only use the get methods

### Features

- [x] Memory usage scales with the array size
- [x] Supports most features of a C++ vector, excluding iterators and time complexity
- [x] Quality of life features that C++ vectors do not have, such as printing the list, sum, product, etc...
- [ ] Ability to store data types other than integers using void pointers (May cause significant changes to code structure, function return values, function behavior, and function parameters)
- [ ] Speed of a C++ vector (unlikely)

##### Compilation

Makefile is provided, run `make` to compile
