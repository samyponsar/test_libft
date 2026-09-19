#!/bin/bash
make -C ..
cc -g -Wall -Wextra -Werror test_libft.c -I.. -L.. -lft -lc -lbsd -o test_libft
valgrind -q --leak-check=full ./test_libft
rm test_libft
