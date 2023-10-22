CFLAGS = -Wall -Wextra -Wpedantic -g -o
SOURCE = src/main.c src/vector.c src/func_helper.c src/func_readonly.c src/func_modifier.c src/func_qualoflife.c 
BINARY = bin/main

all: src/main.c 
	clang $(CFLAGS) $(BINARY) $(SOURCE)
	mv bin/main.dSYM/ debug
