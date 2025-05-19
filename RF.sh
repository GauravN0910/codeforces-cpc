#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <cpp-file>"
    exit 1
fi

cpp_file=$1

if [ ! -f "$cpp_file" ]; then
    echo "Error: File '$cpp_file' not found!"
    exit 2
fi

g++ "$cpp_file" -o a.out

if [ $? -eq 0 ]; then
    ./a.out
    cat output.txt
else
    echo "Compilation failed."
    exit 3
fi