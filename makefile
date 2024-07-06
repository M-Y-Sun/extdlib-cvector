CC ?= gcc
CFLAGS = -I./$(INCL) -g -Wall -Wextra -Wpedantic

MAIN ?=  src/main.c
SRC_DIR := src/implm
INCL := src/include/
BIN ?= bin/main.elf

default: $(MAIN)
	if [ ! -d bin/ ]; then mkdir bin/; fi
	if [ ! -d dbg/ ]; then mkdir dbg/; fi

	$(CC) $(MAIN) $(SRC_DIR)/*.c -o $(BIN) $(CFLAGS) 

	if [ -d dbg/main.elf.dSYM/ ]; then rm -r dbg/main.elf.dSYM/; fi
	if [ -d bin/main.elf.dSYM/ ]; then mv bin/main.elf.dSYM/ dbg//; fi

clean: $(BIN) $(BIN).dSYM/
	rm $(BIN)
	rm -r $(BIN).dSYM/
	
