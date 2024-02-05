<div align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg?logo=c">
  <img src="https://img.shields.io/badge/platform-macOS-blue.svg?logo=macos">
  <img src="https://img.shields.io/badge/platform-Linux-orange.svg?logo=linux"> 
  <img src="https://img.shields.io/badge/platform-Ubuntu-%23E95420.svg?logo=ubuntu">
  <img src="https://custom-icon-badges.demolab.com/github/license/denvercoder1/custom-icon-badges?logo=law">
</div>

# Name Management Program

## Overview
This C program demonstrates the management of names, including functions for generating random names, checking duplicates, printing the list, and manipulating a list of names. The program reads 30 names, removes newline characters, checks for duplicates, prints the input list, and generates and prints 10 different random names.

## Table of Contents
- [Program Structure](#Program-structure)
  - [get_name.c](./get_name.c): Main source file for managing names and demonstrating utility functions.
  - [constants.h](./constants.h): Header file containing constants for managing names.
  - [get_name_util.h](./get_name_util.h): Header file for utility functions managing a list of names.
  - [get_name_util.c](./get_name_util.c): Source file containing utility functions for managing a list of names.
- [Constants](#constants)
- [Utility Functions](#utility-functions)
- [Usage](#usage)
- [License](#license)

## Program Structure

### Constants
- [constants.h](./constants.h): Header file defining constants for managing names.
    - `Macro` NUM_OF_NAMES: The maximum number of names in the list.
    - `Macro` MAX_NAME_LENGTH: The maximum length of each name in the list.

### Utility Functions
- [get_name_util.h](./get_name_util.h): Header file for utility functions managing a list of names.
    - `Macro` FOR_RANGE: Convenient iteration macro over a specified range.
    - `External Declaration` nameList: Two-dimensional array for storing names.
    - `Enumeration` bool: Boolean values enumeration (TRUE, FALSE).
    - `char *` get_name(): Generates a random name from the list.
    - `bool` is_duplicate(): Checks if a new name is a duplicate within a specified range in the name list.
    - `void` print_list(): Prints all the names in the list.
    - `void` remove_newline_char(): Removes the newline character from a name if present.
    - `void` initialize_random_seed(): Initializes the random seed for generating random names.

## Usage
To use the name management program, compile the source files using a C compiler. For example, using GCC:

```bash
gcc get_name.c get_name_util.c -o get_name
```

Follow the on-screen prompts to interact with the name management program.

## License

This repository is licensed under the [MIT License](https://github.com/yehonatanke/OpenU-C-Programming/blob/main/LICENSE).
Feel free to use, modify, and distribute the content as per the terms of the license.

## Author

yehonataKe
