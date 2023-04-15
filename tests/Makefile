# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 01:34:02 by wcorrea-          #+#    #+#              #
#    Updated: 2023/04/15 03:07:51 by wcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libft/libft.a

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ../libft

T1 = part1.c
T2 = part2.c
T3 = bonus.c

tests:	
		${CC} ${CFLAGS} ${INCLUDE} ${T1} ${NAME} -o t1
		${CC} ${CFLAGS} ${INCLUDE} ${T2} ${NAME} -o t2

tbonus:	tests
		${CC} ${CFLAGS} ${INCLUDE} ${T3} ${NAME} -o t3

tclean:
		${RM} t1 t2 t3
		
.PHONY: tests tbonus tclean