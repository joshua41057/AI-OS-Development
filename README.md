# AI-OS-Development

**AI-OS-Development** is a project to develop a custom operating system using deep learning techniques. This project aims to create an efficient OS that can integrate and support future AI models effectively. The OS includes basic functionalities such as a bootloader, kernel, and the ability to print messages on the screen. This README provides a comprehensive guide to setting up, building, and testing the OS.

## Table of Contents

1. [Project Overview](#project-overview)
2. [Technologies](#technologies)
3. [Directory Structure](#directory-structure)
4. [Setup and Installation](#setup-and-installation)
5. [Building the OS](#building-the-os)
6. [Testing the OS](#testing-the-os)
7. [Contributing](#contributing)

## Project Overview

**AI-OS-Development** is a custom operating system project focused on integrating deep learning capabilities to enhance OS efficiency. The project includes:

- **Bootloader:** Initializes the system and loads the kernel.
- **Kernel:** Handles basic system functions and displays messages.
- **Future Features:** To be developed, including advanced AI integration and system management.

## Technologies

- **Programming Languages:** Assembly, C
- **Tools:** NASM, GCC, LD, QEMU, Make, Git
- **Development Environment:** Visual Studio Code or any text editor/IDE of your choice

## Directory Structure

The project is organized as follows:
```
AI-OS-Development/
│
├── bootloader/
│ ├── bootloader.asm # Bootloader source code
│ ├── Makefile # Build script for the bootloader
│
├── kernel/
│ ├── kernel.c # Kernel source code
│ ├── kernel_entry.asm # Kernel entry point in assembly
│ ├── Makefile # Build script for the kernel
│
├── scripts/
│ ├── build.sh # Build and run script
│
├── README.md # This file
└── .gitignore # Git ignore file
```


## Setup and Installation

### Prerequisites

Ensure you have the following installed:

- **NASM:** Assembler for x86 assembly
- **GCC:** GNU Compiler Collection for C programming
- **LD:** GNU Linker
- **QEMU:** Emulator for running your OS
- **Make:** Build automation tool
- **Git:** Version control system

### Installation Steps

1. **Clone the Repository:**

    ```sh
    git clone https://github.com/yourusername/AI-OS-Development.git
    cd AI-OS-Development
    ```

2. **Install Prerequisites:**
   
    - On Ubuntu/Debian:

        ```sh
        sudo apt-get update
        sudo apt-get install nasm gcc gld qemu make git
        ```

    - On macOS (using Homebrew):

        ```sh
        brew install nasm gcc qemu make git
        ```

## Building the OS

### Build Bootloader

Navigate to the `bootloader` directory and run:

```sh
cd bootloader
make
```

### Build Kernel
Navigate to the `kernel` directory and run:

```sh
cd kernel
make
```

### Create Bootable Image
Run the build script to create a bootable image:

```sh
cd ..
scripts/build.sh
```

## Testing the OS
### Run in QEMU
To test the OS, run:

```sh
scripts/build.sh
```

This script builds the OS and starts it in QEMU. You should see the message "Kernel has started successfully!" on the screen.

## Contributing

Contributions are welcome! If you have suggestions, improvements, or bug fixes, please create a pull request or open an issue.