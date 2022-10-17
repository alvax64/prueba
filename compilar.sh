#!/bin/bash
nasm -f elf64 powerimpASM.asm -o powerimpASM.o -g
nasm -f elf64 factimpASM.asm -o factimpASM.o -g
gcc factimpASM.o powerimpASM.o principal.c -lm -o taylor_sin -g
./taylor_sin