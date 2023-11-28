CFLAGS = -Wall -Wextra -Wpedantic -g -o
SOURCE = src/main.c src/func_mand.c src/func_helper.c src/func_readonly.c src/func_modifier.c src/func_qualoflife.c 
BINARY = bin/main

all: src/main.c 
	if [ ! -d bin/ ]; then mkdir bin/; fi
	if [ ! -d dbg/ ]; then mkdir dbg/; fi

	gcc $(CFLAGS) $(BINARY) $(SOURCE)

	mv bin/main.dSYM/ dbg/

