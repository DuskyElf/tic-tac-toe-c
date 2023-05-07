#!/bin/sh

clang main.c models.c -O3 -o tic-tac-toe-c
./tic-tac-toe-c
