# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 01:34:02 by wcorrea-          #+#    #+#              #
#    Updated: 2023/04/15 11:25:21 by wcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libft/libft.a

MAKE = make -C

LIBFT_MAKEFILE = ../libft

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ../libft

T1 = part1.c
T2 = part2.c
T3 = bonus.c

all:	mandatory bonus

onlytests:	all clean

libftall:
		${MAKE} ${LIBFT_MAKEFILE} all
		
libftclean:
		${MAKE} ${LIBFT_MAKEFILE} clean

libftfclean:
		${MAKE} ${LIBFT_MAKEFILE} fclean

libftbonus:
		${MAKE} ${LIBFT_MAKEFILE} bonus

mandatory:	libftall
		${CC} ${CFLAGS} ${INCLUDE} ${T1} ${NAME} -o t1
		${CC} ${CFLAGS} ${INCLUDE} ${T2} ${NAME} -o t2

bonus:	libftbonus
		${CC} ${CFLAGS} ${INCLUDE} ${T3} ${NAME} -o t3

clean:	libftfclean

fclean:	clean
		${RM} t1 t2 t3

re:	fclean all
		
.PHONY: all onlytests mandatory bonus fclean re libftall libftbonus libftclean libftfclean