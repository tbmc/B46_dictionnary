#!/bin/bash
gcc *.c -g
valgrind --tool=memcheck --leak-check=full ./a.out
