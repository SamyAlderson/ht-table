# ht-table
A minimal, single-purpose hash table implementation in C.

## What it does
This project implements a basic hash table with insertion, search, and deletion operations. It's a simple tool to understand the underlying mechanics of a hash table data structure.

## Install
To use ht-table, simply compile the source code:
```bash
gcc -o ht_table ht_table.c
```
This will create an executable called `ht_table`. You can then run it with the following commands:
```bash
./ht_table
```
This will print usage instructions.

## Usage
To use ht-table, simply run the executable with the following options:
```bash
./ht_table -h
./ht_table -i key value
./ht_table -s key
./ht_table -d key
```
Replace `key` and `value` with your desired values.

## Build from source
To build ht-table from source, run the following commands:
```bash
gcc -o ht_table ht_table.c
```
This will create an executable called `ht_table`.

## Project structure
The project consists of the following files:

* `ht_table.c`: The main implementation of the hash table.
* `test_ht_table.c`: A test suite for the hash table implementation.
* `README.md`: This file.

## License
Copyright (c) 2026 SamyAlderson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.