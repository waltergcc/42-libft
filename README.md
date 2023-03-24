# libft

In this project we will create a library that contains several functions that can be used later in other projects. Follow the list of functions that were recreated:

### Part 1 - Libc functions

`atoi` `bzero` `isalnum` `isalpha` `isascii` `isdigit` `isprint` `memccpy` `memchr` `memcmp` `memcpy` `memmove` `memset` `strcat` `strchr` `strcmp` `strcpy` `strdup` `strlcat` `strlen` `strncat` `strncmp` `strncpy` `strnstr` `strrchr` `strstr` `toupper` `tolower`

### Part 2 - Additional functions

`memalloc` `memdel` `strnew` `strdel` `strclr` `striter` `striteri` `strmap` `strmapi` `strequ` `strnequ` `strsub` `strjoin` `strtrim` `strsplit` `itoa` `putchar` `putstr` `putendl` `putnbr` `putchar_fd` `putstr_fd` `putendl_fd` `putnbr_fd`

### Bonus part

`lstnew` `lstdelone` `lstdel` `lstadd` `lstiter` `lstmap`

## Instructions

To create the static library with the functions use the following command:

```bash
make all
```
After the library is generated, to do tests, do the command below:
```bash
make tests
```

And then run any of the tests.
```bash
./tx # Replace x by 1, 2 or 3.
```

## Project Status

| Project | Done |
|:----:|:------------------:|
| part1 | :heavy_check_mark: |
| part2 | :heavy_check_mark: |
| bonus | :heavy_check_mark: |