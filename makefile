CC ?= gcc
CFLAGS := -Wall -Wextra -Wpedantic -g
MAIN ?=  src/main.c
SRC := src/implm/mand.c src/implm/helper.c src/implm/readonly.c src/implm/modifier.c src/implm/qol.c 
BIN ?= bin/main.elf

default: $(MAIN)
	if [ ! -d bin/ ]; then mkdir bin/; fi
	if [ ! -d dbg/ ]; then mkdir dbg/; fi

	$(CC) $(CFLAGS) $(MAIN) $(SRC) -o $(BIN)

	if [ -d dbg/main.elf.dSYM/ ]; then rm -r dbg/main.elf.dSYM/; fi
	if [ -d bin/main.elf.dSYM/ ]; then mv bin/main.elf.dSYM/ dbg//; fi
