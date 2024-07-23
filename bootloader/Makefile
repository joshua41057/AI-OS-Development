# AI-OS-Development/bootloader/Makefile
all: bootloader.bin

bootloader.bin: bootloader.asm
	nasm -f bin bootloader.asm -o bootloader.bin

clean:
	rm -f bootloader.bin
