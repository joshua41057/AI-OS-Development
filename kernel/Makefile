# AI-OS-Development/kernel/Makefile
C_SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = ${C_SOURCES:.c=.o}

all: kernel.bin

kernel.bin: kernel_entry.o ${OBJ}
	ld -m elf_i386 -o kernel.bin -T linker.ld kernel_entry.o ${OBJ}

%.o: %.c ${HEADERS}
	gcc -m32 -ffreestanding -c $< -o $@

kernel_entry.o: kernel_entry.asm
	nasm -f elf -o kernel_entry.o kernel_entry.asm

clean:
	rm -f *.bin *.o
