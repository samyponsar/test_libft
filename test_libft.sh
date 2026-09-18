#!/bin/bash
make -C ..
cc -Wall -Wextra -Werror test_libft.c -I.. -L.. -lft -lc -lbsd -o test_libft
./test_libft
rm test_libft
