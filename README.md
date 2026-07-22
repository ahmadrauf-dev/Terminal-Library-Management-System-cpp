# Library Management System V1.0

A console based Library manegement system built in c++ by using concepts of Object ORiented Programing

## Features

- List all available books
- Add Books to Library DB
- Remove Books From Library DB
- Issue Available Book
- Return Issued Book

## Requirements

- A C++17-compatible compiler (e.g. `g++` 7 or newer)

## Build

```bash
g++ -std=c++17 -Wall -Wextra -o library_management library_management.cpp
```

## Run

```bash
./library_management
```

You'll see a numbered menu. Enter a number and press Enter to choose an action; enter `0` to exit.

                Library Mangement System
1. List Available Books
2. Add books
3. Remove Books
4. Issue Books
5. Return Books
6. Exit

## Data files

-"Lib_rec.txt" stores whole record of files 

It First stores Id of book then name authors name and Issue Status all sperated by spaces so it remains easy to modify and update

## known Limitations

- Remove book feature was removed as it was not working properly
