# Week4_Assignment
# Python C/C++ Integration Assignment

This repo contains my assignment on integrating C/C++ with Python.

## Requirements
- Python 3.x
- GCC compiler
- pybind11 library

## Setup
```bash
pip3 install pybind11
```

## Question 1: C Extension Module (Square Function)
Simple C function that calculates square of a number.

**Build:**
```bash
cd question1
python3 setup.py build_ext --inplace
```

**Run:**
```bash
python3 test_square.py
```

## Question 2: ctypes String Library
C library with string manipulation using ctypes.

**Build:**
```bash
cd question2
gcc -shared -fPIC -o string_lib.so string_lib.c
```

**Run:**
```bash
python3 test_ctypes.py
```

## Question 3: pybind11 String Concatenation
C++ function for concatenating strings using pybind11.

**Build:**
```bash
cd question3
python3 setup.py build_ext --inplace
```

**Run:**
```bash
python3 test_concat.py
```

## Question 5: Integer Array Management
C extension module for managing integer arrays.

**Build:**
```bash
cd question5
python3 setup.py build_ext --inplace
```

**Run:**
```bash
python3 test_array.py
```

## Notes
- Tested on macOS
- Make sure to run build commands before running test files
- Each question is in separate folder
