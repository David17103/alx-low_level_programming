#!/bin/bash

c_files=$(find . -maxdepth 1 -type f -name "*.c")

for file in $c_files; do
    gcc -c -fPIC "$file" -o "${file%.c}.o"
done

gcc -shared -o liball.so *.o

rm -f *.o

