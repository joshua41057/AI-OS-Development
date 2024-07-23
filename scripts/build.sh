#!/bin/bash

set -e

echo "Building the bootloader..."
# Build the bootloader
cd ..
cd bootloader
make clean
make all || { echo "Bootloader build failed"; exit 1; }
cd ..

echo "Building the kernel..."
# Build the kernel
cd kernel
make clean
make all || { echo "Kernel build failed"; exit 1; }
cd ..

echo "Creating bootable image..."
# Create a bootable image
dd if=/dev/zero of=boot.img bs=512 count=2880 || { echo "Failed to create boot image"; exit 1; }
dd if=bootloader/bootloader.bin of=boot.img conv=notrunc || { echo "Failed to add bootloader to boot image"; exit 1; }
dd if=kernel/kernel.bin of=boot.img seek=1 conv=notrunc || { echo "Failed to add kernel to boot image"; exit 1; }

echo "Running the OS in QEMU..."
# Run the OS in QEMU
qemu-system-x86_64 -drive format=raw,file=boot.img || { echo "Failed to start QEMU"; exit 1; }
