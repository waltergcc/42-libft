
NAME = libft.a

PART1 = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c \
		ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_atoi.c \
		ft_strlen.c ft_strlcat.c ft_strncmp.c ft_strdup.c \
		ft_memcpy.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_bzero.c \
		ft_memchr.c ft_memcmp.c ft_memset.c ft_memmove.c

PART2 = ft_itoa.c ft_strjoin.c ft_split.c ft_striteri.c \
		ft_strmapi.c ft_strsub.c ft_strtrim.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd.c ft_lstdelone.c ft_lstdel.c \
		ft_lstiter.c ft_lstmap.c

T1 = tests/part1.c
T2 = tests/part2.c
T3 = tests/bonus.c

SRC = ${PART1} ${PART2}

OBJS = ${SRC:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}

HEADER = libft.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS} ${HEADER}

all:	${NAME}

bonus:	$(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
		${RM} ${OBJS} $(BONUS_OBJS)

fclean: clean
		${RM} ${NAME}

re: fclean all

tests:
		${CC} ${CFLAGS} ${INCLUDE} ${T1} ${NAME} -o t1
		${CC} ${CFLAGS} ${INCLUDE} ${T2} ${NAME} -o t2

tbonus:
		${CC} ${CFLAGS} ${INCLUDE} ${T3} ${NAME} -o t3

tclean:
		rm t1 t2 t3

.PHONY: all clean fclean re tests tclean
