CFLAGS = -Wall -Wextra -Wpedantic -g -o
SOURCE = src/main.c src/mand.c src/func_helper.c src/func_readonly.c src/func_modifier.c src/func_qualoflife.c 
BINARY = bin/main

all: src/main.c 
	clang $(CFLAGS) $(BINARY) $(SOURCE)
	rm -r debug/main.dSYM
	mv bin/main.dSYM/ debug
