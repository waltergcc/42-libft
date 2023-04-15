# libft

This is the libft project from 42, a library with common functions in the C language. 

## Implemented functions

The library implements the following functions:

### Part 1

`ft_memset` `ft_bzero` `ft_memcpy` `ft_memccpy` `ft_memmove` `ft_memchr` `ft_memcmp` `ft_strlen` `ft_strlcpy` `ft_strlcat` `ft_strchr` `ft_strrchr` `ft_strnstr` `ft_strncmp` `ft_atoi` `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` `ft_toupper` `ft_tolower`

### Part 2

`ft_substr` `ft_strjoin` `ft_strtrim` `ft_split` `ft_itoa` `ft_strmapi` `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd`

### Bonus

`ft_lstnew` `ft_lstadd_front` `ft_lstsize` `ft_lstlast` `ft_lstadd_back` `ft_lstdelone` `ft_lstclear` `ft_lstiter` `ft_lstmap`

## Files

### /libft

The libft directory contains the following files:

- **Makefile:** file that defines the compilation rules to generate the libft.a library.
- **ft_*.c:** files containing the functions of the libft.a library.
- **libft.h:** header files

### /tests

The tests directory contains the following files:

- **Makefile:** file that defines the compilation rules to generate the test executables.
- **part1.c:** test file for the functions of part 1 of the library.
- **part2.c:** test file for the functions of part 2 of the library.
- **bonus.c:** test file for the bonus functions of the library.
- **tests.h, bonus.h:** header files

## Compilation

### libft

To compile the libft.a library with the mandatory functions, navigate to the libft directory and execute the following command:

```bash
make all
```
To compile the library with the mandatory functions and bonus functions, execute the following command:
```bash
make bonus
```
To clean the object files generated by the compilation, execute the following command:
```bash
make clean
```
To remove all files generated by the compilation, execute the following command:
```bash
make fclean
```
### tests

To compile the test files, it's necessary to compile the libft.a library first. To compile the libft.a library and the test files, navigate to the tests directory and execute the following command:
```bash
make all
```
To compile the library with only output the test files, execute the following command:

```bash
make onlytests
```

To compile the library with only the mandatory functions, execute the following command:
```bash
make mandatory
```

To compile the library with only the bonus functions, execute the following command:
```bash
make bonus
```

To clean the object files generated in the libft folder, execute the following command:
```bash
make clean
```
To remove all files generated in the libft folder and tests, execute the following command:
```bash
make fclean
```

## Run

To execute the test files, in the tests directory  execute the files generated by the compilation. For example:
```bash
./t1
./t2
./t3
```

## Project Status

| Project | Done |
|:----:|:------------------:|
| part1 | :heavy_check_mark: |
| part2 | :heavy_check_mark: |
| bonus | :heavy_check_mark: |