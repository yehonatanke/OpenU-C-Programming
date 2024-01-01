# Taylor Series Cosine Calculator - C Assignment

## Overview

This program consists of a C program for calculating the cosine of an angle using the Taylor series expansion with a configurable error limit. The main goal is to provide an approximation of the cosine function and compare it with the standard library `cos` function.

## File Structure

- **my_cos.c**: The main program file containing the source code for the custom cosine calculator.
- **Makefile**: The Makefile for building the program, with configurations for compilation and linking.


## Environment

- **Operating System:** Ubuntu
- **Compiler:** GCC (GNU Compiler Collection)

## Prerequisites

Ensure that you have the GCC compiler installed on your Ubuntu system. You can install it using the following command:

```bash
sudo apt-get update
sudo apt-get install build-essential
```

## Implementation Details

### `my_cos.c`

#### Functions

- **my_cos(double x):** Calculates the cosine of a given angle using the Taylor series expansion.

#### Variables

- `sum`: The final result, the sum of the Taylor series of cos(x).
- `term`: The value of the Taylor series to be added.
- `factorial`: The current factorial value.
- `i`: The iterator for the Taylor series expansion.


### `Makefile`

#### Targets

- **all:** Builds the program.
- **clean:** Removes the build directory.
- **build_env:** Creates necessary directories for the build process.
- **zip:** Creates a zip file for submission.

## Build and Run

### Prerequisites

- **Compiler:** GCC (GNU Compiler Collection)

### Build the Program:

1. Open a terminal and navigate to the project directory.
2. Run the command `make` to build the executable.

### Run the Program:

1. After building, execute the program using `./build/bin/my_cos`.

### Input Instructions:

1. Enter a value for `x` when prompted.
2. The program will display the computed cosine using both the custom `my_cos` function and the standard library `cos` function.

## Mathematical Explanation

The Taylor series expansion for the cosine function is given by:

$`cos(x) = 1 - \frac{x^2}{2!} + \frac{x^4}{4!} - \frac{x^6}{6!} + \ldots`$

The custom `my_cos` function in `my_cos.c` uses this series to approximate the cosine of a given angle \(x\). The series is iteratively computed until the error term falls below the desired limit, which is set to $1.0 \times 10^{-6}$.


## Build Details

### `Makefile`

- **CC:** gcc (Compiler)
- **CFLAGS:** -ansi -pedantic -Wall (Compilation flags)
- **LDFLAGS:** -lm (Linking flags)
- **PROG_NAME:** my_cos (Executable name)
- **OBJS:** my_cos.o (Object files)
- **BUILD_DIR:** build (Build directory)
- **OBJ_DIR:** $(BUILD_DIR)/obj (Object files directory)
- **BIN_DIR:** $(BUILD_DIR)/bin (Executable directory)
- **ZIP_NAME:** mmn11.zip (Zip file for submission)

## License

This program is released under the [MIT License](LICENSE).

### Author

yehonatanke 

