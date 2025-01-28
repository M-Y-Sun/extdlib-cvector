CC = clang
CFLAGS = -I./$(INCL) -g -Wall -Wextra -Wpedantic
OFLAG ?= O1

FILE = main
MAIN ?=  src/$(FILE).c
BIN = $(FILE).elf

IMPL_DIR := src/implm
INCL := src/include/

MKDIRS = /bin/bash -c 'if [ ! -d bin/ ]; then mkdir bin/; fi; if [ ! -d dbg/ ]; then mkdir dbg/; fi'
REPLACE_FILES = /bin/bash -c 'if [ -d dbg/$(BIN).dSYM/ ]; then rm -r dbg/$(BIN).dSYM/; fi; if [ -d bin/$(BIN).dSYM/ ]; then mv bin/$(BIN).dSYM/ dbg//; fi'

CCPFX = $(CC) $(MAIN) $(IMPL_DIR)/*.c -o bin/$(BIN) $(CFLAGS) 

default: $(MAIN)
	$(MKDIRS)
	$(CCPFX) -$(OFLAG)
	$(REPLACE_FILES)

fast:
	$(MKDIRS)
	$(CCPFX) -Ofast
	$(REPLACE_FILES)

debug:
	$(MKDIRS)
	$(CCPFX) -Og
	$(REPLACE_FILES)

size:
	$(MKDIRS)
	$(CCPFX) -Os
	$(REPLACE_FILES)

verbose: $(MAIN)
	$(MKDIRS)
	$(CCPFX) -$(OFLAG) -v
	$(REPLACE_FILES)

clean: bin/$(BIN) dbg/$(BIN).dSYM/
	rm bin/$(BIN)
	rm -r dbg/$(BIN).dSYM/
