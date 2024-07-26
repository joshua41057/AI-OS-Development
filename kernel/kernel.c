// AI-OS-Development/kernel/kernel.c

extern void gdt_install();
extern void idt_install();

// Video memory address for text mode
#define VIDEO_MEMORY_ADDRESS 0xB8000
#define VIDEO_MEMORY_SIZE    0xFA00  // 80x25 characters, 2 bytes per character

// Function to print a single character at a specific position
void print_char(char c, int col, int row) {
    unsigned short* video_memory = (unsigned short*)VIDEO_MEMORY_ADDRESS;
    video_memory[row * 80 + col] = (video_memory[row * 80 + col] & 0xFF00) | c;
}

// Function to print a string at a specific position
void print_string(const char* str, int col, int row) {
    unsigned short* video_memory = (unsigned short*)VIDEO_MEMORY_ADDRESS;
    while (*str) {
        video_memory[row * 80 + col++] = (video_memory[row * 80 + col] & 0xFF00) | *str++;
    }
}

// Function to initialize video memory and print an introductory message
void kernel_init() {
    // Clear screen by filling video memory with spaces
    unsigned short* video_memory = (unsigned short*)VIDEO_MEMORY_ADDRESS;
    for (int i = 0; i < VIDEO_MEMORY_SIZE / 2; ++i) {
        video_memory[i] = (0x0F << 8) | ' ';  // White on black
    }
    // Print a message to indicate that the kernel has started
    print_string("Kernel has started successfully!", 0, 0);
}

// Main kernel function
void kernel_main() {
    gdt_install();
    idt_install();
    kernel_init();  // Initialize the kernel and print a startup message

    // Main loop to keep the kernel running
    while (1) {
        // Here you can add code to handle tasks, manage hardware, etc.
    }
}
