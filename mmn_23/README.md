<div align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg?logo=c">
  <img src="https://img.shields.io/badge/platform-Linux-orange.svg?logo=linux"> 
  <img src="https://img.shields.io/badge/platform-Ubuntu-%23E95420.svg?logo=ubuntu">
  <img src="https://custom-icon-badges.demolab.com/github/license/denvercoder1/custom-icon-badges?logo=law">
</div>

# Word Indexer

## Description
This program generates an index for a given text file. It reads the contents of the file, extracts words, and creates an index that lists each word along with the line numbers on which it appears in the file. It then sorts the words lexicographically and prints the sorted index.

## Table of Contents
- [Features](#Features)
- [Program Structure](#program-structure)
    - [Constants](#constants)
    - [Error Utility](#error-utility)
    - [Globals](#globals)
    - [Hash Utility](#hash-utility)
    - [Index](#index)
    - [Utility](#utility)
- [Makefile](#makefile)
- [Installation and Usage](#Installation-and-Usage)
- [Sample Input and Output](#sample-input-and-output)
- [License](#license)

## Features
- Generates an index for a given text file.
- Handles words of varying lengths.
- Supports files with multiple occurrences of the same word on different lines.
- Print the index in lexicographic order.

## Program Structure

### Constants
The `constants.h` file defines various constants used throughout the program, such as maximum line length, hash table size, valid argument count, and whitespace characters.

### Error Utility
The `error_utility.h` file contains error handling utilities, including functions for printing error messages to the error log stream.

### Globals
The `globals.h` file contains global definitions and structures used throughout the program, including structures for linked list nodes and word entries in the index, as well as an enumeration for boolean values.

### Hash Utility
The `hash_utility.h` file contains utility functions for hashing and indexing words, including a function for computing hash values of strings, adding words to an index along with line numbers, and checking the existence of words in an array.

### Index
The `index.h` file declares functions for processing files, building an index, and printing the sorted index. This is the main program file.

### Utility
The `utility.h` file contains utility functions for processing data and memory management, including functions for string comparison, printing word occurrences, sorting strings, memory allocation with error checking, and string duplication.

## Makefile
The `Makefile` contains rules for compiling the program and creating the executable.

## Usage
To use the program, follow these steps:
1. Compile the program using the provided `Makefile`.
2. Run the compiled program with the input file as a command-line argument.

## Installation and Usage
### Installation
1. Clone the repository: `git clone https://github.com/yehonatanke/OpenU-C-Programming/tree/main/mmn_23.git`
2. Compile the program: ```gcc -o word_indexer main.c utility.c error_utility.c hash_utility.c -I.```
```bash
path/to/program/mmn23$ make
```
### Usage
Run the program:
```bash
path/to/program/mmn23$ 
for file in `<input_files>`/input_*.txt; do
  echo "Processing file: $file"
  ./build/bin/index "$file"
  echo   # Adding an empty echo to print a newline
done
```

- Replace `<input_files>` with the path to the text files you want to index.
- Ensure that the text files exist and are readable.

## Sample Input and Output

**Input (input.txt):**
```bash
jack and jill
went up the hill
jack and jill
went down the hill
then the hill disappeared
```

**Output:**
```bash
and - appears in lines 1,3 
disappeared -  appears in line 5 
down  - appears in line 4
hill  - appears in lines 2,4,5 
jack  - appears in lines 1,3 
jill -  appears in lines 1,3 
the  - appears in lines 2,4,5 
then  - appears in line 5
up  - appears in line 2 
went  - appears in lines 2,4
```

## License
This project is licensed under the MIT License - see the [LICENSE](https://github.com/yehonatanke/OpenU-C-Programming/blob/main/LICENSE) file for details.

## Author
yehonatakey
