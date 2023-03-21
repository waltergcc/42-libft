#!/bin/bash

gcc -Wall -Wextra -Werror -I include tests/part2.c libft.a -o part2
gcc -Wall -Wextra -Werror -I include tests/bonus.c libft.a -o bonus
gcc -Wall -Wextra -Werror -I include tests/part1.c libft.a -o part1