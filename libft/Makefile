
NAME = libft.a

PART1 = src/ft_tolower.c src/ft_toupper.c src/ft_isprint.c src/ft_isascii.c \
		src/ft_isalnum.c src/ft_isdigit.c src/ft_isalpha.c src/ft_atoi.c \
		src/ft_strlen.c src/ft_strcpy.c src/ft_strncpy.c src/ft_strcat.c \
		src/ft_strncat.c src/ft_strlcat.c src/ft_strcmp.c src/ft_strncmp.c \
		src/ft_strdup.c src/ft_strstr.c src/ft_memcpy.c src/ft_strchr.c \
		src/ft_strrchr.c src/ft_strnstr.c src/ft_bzero.c src/ft_memccpy.c \
		src/ft_memchr.c src/ft_memcmp.c src/ft_memset.c src/ft_memmove.c

PART2 = src/ft_putchar.c src/ft_putstr.c src/ft_putnbr.c src/ft_itoa.c \
		src/ft_strjoin.c src/ft_strsplit.c src/ft_memalloc.c src/ft_memdel.c \
		src/ft_strnew.c src/ft_strdel.c src/ft_strclr.c src/ft_striter.c \
		src/ft_striteri.c src/ft_strmap.c src/ft_strmapi.c src/ft_strequ.c \
		src/ft_strnequ.c src/ft_strsub.c src/ft_strtrim.c src/ft_putendl.c \
		src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c

BONUS = src/ft_lstnew.c src/ft_lstadd.c src/ft_lstdelone.c src/ft_lstdel.c \
		src/ft_lstiter.c src/ft_lstmap.c

T1 = tests/part1.c
T2 = tests/part2.c
T3 = tests/bonus.c

SRC = ${PART1} ${PART2} ${BONUS}

OBJS = ${SRC:.c=.o}

HEADER = include/libft.h

CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS} ${HEADER}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

tests:
		${CC} ${CFLAGS} ${INCLUDE} ${T1} ${NAME} -o t1
		${CC} ${CFLAGS} ${INCLUDE} ${T2} ${NAME} -o t2
		${CC} ${CFLAGS} ${INCLUDE} ${T3} ${NAME} -o t3

tclean:
		rm t1 t2 t3

.PHONY: all clean fclean re tests tclean
