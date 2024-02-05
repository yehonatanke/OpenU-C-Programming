<div align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg?logo=c">
  <img src="https://img.shields.io/badge/platform-Linux-orange.svg?logo=linux"> 
  <img src="https://img.shields.io/badge/platform-Ubuntu-%23E95420.svg?logo=ubuntu">
  <img src="https://custom-icon-badges.demolab.com/github/license/denvercoder1/custom-icon-badges?logo=law">
</div>

# Matrix Processing Program

## Overview
This C90 program implements a matrix processing application, providing functionalities for initializing matrices, handling user input, and performing various matrix operations. The program is designed for modularity and efficiency in matrix manipulation.

## Table of Contents
- [Program Structure](#program-structure)
  - [Constants](#constants)
  - [Error Utility](#error-utility)
  - [Main Matrix Functions](#main-matrix-functions)
  - [Message Utility](#message-utility)
  - [Utility](#utility)
  - [Globals](#globals)
- [Matrix Operations](#matrix-operations)
- [Makefile](#makefile)
- [Platform](#platform)
- [Usage](#usage)
- [License](#license)
- [License](#license)

## Program Structure

### Constants
- [constants.h](./constants.h): Header file containing constant values for the matrix processing program.
    - Defines constants for the number of rows and columns in matrices, maximum user input length, and the initial size of a line buffer.

### Error Utility
- [error_utility.h](./error_utility.h): Header file containing error constants and utility macros for error handling in the matrix processing program.
    - Provides macros for common error messages related to matrix processing.
    - Utility macros for checking illegal comma usage, extraneous text, missing arguments, missing commas, etc.
    - Includes an `error_handling` function to print formatted error messages.

### Main Matrix Functions
- [mainmat.h](./mainmat.h): Header file containing functions for initializing matrices and processing the main functionality of the matrix processing program.
    - Initializes predefined matrices to zero.
    - Processes the main functionality of the program, handling user input in a loop until termination.
- [process_input.h](./process_input.h): Header file for processing user input.
    - Defines functions for analyzing and handling user input.

### Message Utility
- [message_utility.h](./message_utility.h): Header file containing message constants for the matrix processing program.
    - Provides constants for opening and exit messages, a message for empty lines, and a message for undefined command names.

### Utility
- [utility.h](./utility.h): Header file containing utility macros and functions for the matrix processing program.
    - Includes macros for pointer manipulation, command analysis, and functions for handling memory allocation.
    - Designed to enhance the functionality of matrix processing, offering tools for efficient command parsing, matrix operations, and dynamic memory management.

### Globals
- [globals.h](./globals.h): Header file containing global constants and enumerations for the matrix processing program.
    - Defines constants for maximum matrix name length, the number of supported functions, and the total number of matrices.
    - Enumerations for boolean values, command types, and matrix names.

## Matrix Operations
- [mainmat.h](./mainmat.h): Header file containing the following legitimate matrix operations:
    1. `READ_MAT`: Reads matrix values from an array.
    2. `PRINT_MAT`: Prints the contents of a matrix.
    3. `ADD_MAT`: Performs matrix addition.
    4. `SUB_MAT`: Performs matrix subtraction.
    5. `MUL_MAT`: Performs matrix multiplication.
    6. `MUL_SCALAR`: Performs scalar multiplication.
    7. `TRANS_MAT`: Performs matrix transposition.

## Makefile
- [Makefile](./Makefile): Provides instructions for building the matrix processing program on Ubuntu.
    - Compiles the source files and creates an executable named `matrix_program`.
    - Run the program using `./matrix_program`.

## Platform
- The matrix processing program is developed and tested on the Ubuntu platform.

## Usage
To use the matrix processing program, include the necessary header files in your project, and implement the functions based on your requirements. The main functionality of the program is located in [main.c](./main.c), where matrices are initialized, and the user input is processed in a loop until termination.

```bash
gcc main.c -o matrix_program
./matrix_program
```
Follow the on-screen prompts to interact with the matrix processing program.


## License
This matrix processing program is licensed under the [MIT License](./LICENSE).


## Author
yehonatakey
