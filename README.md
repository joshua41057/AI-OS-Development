# AI-OS-Development

**AI-OS-Development** is a project to develop a custom operating system with integrated deep learning capabilities. This project aims to create an efficient OS by leveraging AI techniques to optimize functionalities such as task scheduling and memory management. It includes basic functionalities like a bootloader, kernel, and data logging mechanisms to support AI training and predictions.

## Table of Contents

1. [Project Overview](#project-overview)
2. [Technologies](#technologies)
3. [Directory Structure](#directory-structure)
4. [Setup and Installation](#setup-and-installation)
5. [Building the OS](#building-the-os)
6. [Testing the OS](#testing-the-os)
7. [Integrating AI](#integrating-ai)
8. [Contributing](#contributing)

## Project Overview

**AI-OS-Development** is a custom operating system project focused on integrating deep learning capabilities to enhance OS efficiency. The project includes:

- **Bootloader:** Initializes the system and loads the kernel.
- **Kernel:** Handles basic system functions, displays messages, logs task metrics.
- **AI Integration:** Predictive task scheduling using RNN models, efficient memory management.

## Technologies

- **Programming Languages:** Assembly, C, Python
- **Tools:** NASM, GCC, LD, QEMU, Make, Git
- **Development Environment:** Visual Studio Code or any text editor/IDE of your choice
- **AI Tools:** PyTorch (for training models)

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
| ├── gdt_idt.c # GDT and IDT initialization code
│ ├── Makefile # Build script for the kernel
│
├── models/
| |──task_predictor_rnn.py # Script to train RNN for task scheduling
│ ├── task_predictor_rnn.pth # Trained RNN model parameters
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
- **Python & PyTorch:** For training AI models

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
        sudo apt-get install nasm gcc gld qemu make git python3 python3-pip
        pip3 install torch
        ```

    - On macOS (using Homebrew):

        ```sh
        brew install nasm gcc qemu make git
        brew install python
        pip3 install torch
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

### Build AI Model
If you have not yet trained the AI model, navigate to the models directory and run the training script:

```sh
cd models
python3 task_predictor_rnn.py
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

## Integrating AI

### Train and Export the AI Model

#### Train the Model:

Ensure you have logged enough task data. Use the provided `task_predictor_rnn.py` script to train the RNN model:

```sh
cd models
python3 task_predictor_rnn.py
```
#### Export and Load Model in Kerne:
Export trained model parameters to a C-compatible format and update the kernel to load and use these parameters:

```
// In kernel/main.c
void load_rnn_model(const char *filename); // Load model function
```

### Predictive Scheduling
Integrate predictions from the trained model to optimize task scheduling:

```
void schedule_task(int pid) {
    // Load input features for the model
    float input_features[3] = { /* Current CPU usage, previous exec time, etc. */ };

    // Predict using the model
    float predicted_time = predict_execution_time(input_features);

    // Use predicted_time to make scheduling decision
}
```



## Contributing

Contributions are welcome! If you have suggestions, improvements, or bug fixes, please create a pull request or open an issue.