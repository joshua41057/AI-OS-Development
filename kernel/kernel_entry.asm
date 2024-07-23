; AI-OS-Development/kernel/kernel_entry.asm
BITS 32
section .text
global _start

_start:
    cli                 ; Disable interrupts
    mov eax, cr0
    or eax, 1           ; Set the PE (Protected Mode Enable) bit in CR0
    mov cr0, eax
    jmp 08h:init_pm     ; Far jump to flush the prefetch queue

init_pm:
    ; Load kernel main
    extern kernel_main
    call kernel_main

hang:
    hlt
    jmp hang
