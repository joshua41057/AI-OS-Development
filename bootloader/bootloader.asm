; AI-OS-Development/bootloader/bootloader.asm
BITS 16
ORG 0x7C00

; Set up a stack
MOV AX, 0x0000
MOV SS, AX
MOV SP, 0x7C00

; Print a message
MOV SI, message
CALL print_string

; Infinite loop
JMP $

print_string:
    MOV AH, 0x0E
.repeat:
    LODSB
    OR AL, AL
    JZ .done
    INT 0x10
    JMP .repeat
.done:
    RET

message: DB 'Bootloader loaded successfully!', 0

TIMES 510 - ($ - $$) DB 0
DW 0xAA55
