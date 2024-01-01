# Dollar Converter - C Assignment

## Overview

This program, named **Dollar Converter**, is a C assignment designed to convert shekel amounts to dollars based on a given dollar rate. The assignment involves implementing user input, calculations, and output display.

## File Structure

- **doll.c**: The main program file containing the source code.
- **Makefile**: The Makefile for building the program.


## Environment

- **Operating System:** Ubuntu
- **Compiler:** GCC (GNU Compiler Collection)

## Prerequisites

Ensure that you have the GCC compiler installed on your Ubuntu system. You can install it using the following command:

```bash
sudo apt-get update
sudo apt-get install build-essential
```

## Usage

1. **Build the Program:**
   - Open a terminal and navigate to the project directory.
   - Run the command `make` to build the executable.

2. **Run the Program:**
   - After building, execute the program using `./build/bin/doll`.

3. **Input Instructions:**
   - Enter the dollar rate followed by shekel amounts in dollars (press Ctrl-D, EOF, or insert a non-integer to finish).
   - The program will display a table of equivalent dollar amounts for each shekel value.

## Code Details

- **doll.c:**
  - The program uses an array to store shekel rates and calculates equivalent dollar amounts.
  - It displays the results in a table format, including the total sum of dollar and shekel amounts.

- **Makefile:**
  - The Makefile automates the build process.
  - It compiles the source code into an executable named `doll`.
  - The `clean` target removes the build directory.
  - The `zip` target creates a zip file excluding unnecessary files.


## Build and Run

### Build the Program:

1. Open a terminal and navigate to the project directory.
2. Run the command `make` to build the executable.

### Run the Program:

1. After building, execute the program using `./build/bin/doll`.

### Input Instructions:

- Enter the dollar rate followed by shekel amounts in dollars (press Ctrl-D, EOF, or insert a non-integer to finish).
- The program will display a table of equivalent dollar amounts for each shekel value.

## Code Details

### main.c:

- The program uses an array to store shekel rates and calculates equivalent dollar amounts.
- It displays the results in a table format, including the total sum of dollar and shekel amounts.

### Makefile:

- The Makefile automates the build process.
- It compiles the source code into an executable named `doll`.
- The `clean` target removes the build directory.
- The `zip` target creates a zip file excluding unnecessary files.

## Build and Run

- To build the program, run: `make`

- To execute the program, run: `./build/bin/doll`

- To execute the program, run: `./build/bin/doll`

- To clean the build directory, run: `make clean`

- To create a zip file for submission, run: `make zip`

This will create a mmn11.zip file excluding unnecessary files.

## License

This program is released under the [MIT License](LICENSE).

### Author

yehonatanke
