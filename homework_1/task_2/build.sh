#!/usr/bin/env bash

# Make the build directory.
mkdir build

# Compile objects to build the library ipb_arithmetic.
c++ -std=c++17 -Iinclude/ -c src/subtract.cpp -o build/subtract.o
c++ -std=c++17 -Iinclude/ -c src/sum.cpp -o build/sum.o

# Create ip_arithmetic library by archiving the two objects.
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

# Compile main.cpp using the library
c++ -std=c++17 -Iinclude/ -c src/main.cpp -o build/main.o
c++ -std=c++17 build/main.o -Iinclude/ -Lbuild/ -lipb_arithmetic -o build/main

# Copy files to results
cp build/main results/bin/
cp build/libipb_arithmetic.a results/lib/
