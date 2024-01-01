CFLAGS = -Wall -Wextra -Wpedantic -g -o
SOURCE = src/main.c src/implm/mand.c src/implm/helper.c src/implm/readonly.c src/implm/modifier.c src/implm/qol.c 
BINARY = bin/main.elf

default: gnu

gnu: src/main.c 
	if [ ! -d bin/ ]; then mkdir bin/; fi
	if [ ! -d dbg/ ]; then mkdir dbg/; fi

	gcc $(CFLAGS) $(BINARY) $(SOURCE)

	if [ -d dbg/main.elf.dSYM/ ]; then rm -r dbg/main.elf.dSYM/; fi
	if [ -d bin/main.elf.dSYM/ ]; then mv bin/main.elf.dSYM/ dbg//; fi

clang: src/main.c
	if [ ! -d bin/ ]; then mkdir bin/; fi
	if [ ! -d dbg/ ]; then mkdir dbg/; fi

	clang $(CFLAGS) $(BINARY) $(SOURCE)

	if [ -d dbg/main.elf.dSYM/ ]; then rm -r dbg/main.elf.dSYM/; fi
	if [ -d bin/main.elf.dSYM/ ]; then mv bin/main.elf.dSYM/ dbg//; fi
