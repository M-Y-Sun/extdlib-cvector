CFLAGS = -Wall -Wextra -Wpedantic -g -o
SOURCE = src/main.c src/implementation/mand.c src/implementation/helper.c src/implementation/readonly.c src/implementation/modifier.c src/implementation/qualoflife.c 
BINARY = bin/main.elf

all: src/main.c 
	if [ ! -d bin/ ]; then mkdir bin/; fi
	if [ ! -d dbg/ ]; then mkdir dbg/; fi

	gcc $(CFLAGS) $(BINARY) $(SOURCE)

	if [ -d dbg/main.elf.dSYM/ ]; then rm -r dbg/main.elf.dSYM/; fi
	if [ -d bin/main.elf.dSYM/ ]; then mv bin/main.elf.dSYM/ dbg//; fi

