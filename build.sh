#!/bin/sh

clang main.c models.c -O3 -o main
./main
