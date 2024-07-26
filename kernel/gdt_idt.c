#include <stdint.h>

struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

struct idt_entry {
    uint16_t base_low;
    uint16_t sel;        // Our kernel segment goes here!
    uint8_t always0;     // This will ALWAYS be set to 0!
    uint8_t flags;       // Set using the above table!
    uint16_t base_high;
} __attribute__((packed));

struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

// Create an array of GDT entries, and a special pointer to give to the CPU
struct gdt_entry gdt[3];
struct gdt_ptr gp;

// Create an array of IDT entries, and a special pointer to give to the CPU
struct idt_entry idt[256];
struct idt_ptr idtp;

extern void gdt_flush(uint32_t);
extern void idt_flush(uint32_t);

void mem_set(uint8_t *dest, uint8_t val, uint32_t len) {
    for (; len != 0; len--) *dest++ = val;
}

static void gdt_set_gate(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = (limit >> 16) & 0x0F;
    gdt[num].granularity |= gran & 0xF0;
    gdt[num].access = access;
}

static void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].base_low = (base & 0xFFFF);
    idt[num].base_high = (base >> 16) & 0xFFFF;
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}

void gdt_install() {
    gp.limit = (sizeof(struct gdt_entry) * 3) - 1;
    gp.base = (uint32_t)&gdt;

    gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment

    gdt_flush((uint32_t)&gp);
}

void idt_install() {
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = (uint32_t)&idt;

    mem_set((uint8_t *)&idt, 0, sizeof(struct idt_entry) * 256);

    idt_flush((uint32_t)&idtp);
}

void idt_load(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt_set_gate(num, base, sel, flags);
}