# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:40:32 by lbertran          #+#    #+#              #
#    Updated: 2021/04/06 10:25:14 by lbertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC		= error.c \
			map.c \
			utils.c \
			operations/push.c \
			operations/reverse_rotate.c \
			operations/rotate.c \
			operations/swap.c \
			parsing/parser.c \
			stack/basics.c \
			stack/color.c \
			stack/get.c \
			stack/median.c \
			stack/next.c \
			stack/peek_pop.c \
			stack/print.c \
			stack/range.c \
			stack/top.c \
			stack/utils.c
OBJS	= ${SRC:.c=.o}
INCS	= ../includes
NAME	= common.a
LIBC	= ar rcs
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g3 -O3

%.o: %.c ${INCS}
	${CC} ${CFLAGS} -c $< -o $@ -I${INCS}

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}
	
all: ${NAME}

bonus: all

clean:
	${RM} ${OBJS}
	${RM} a.out

fclean: clean
	${RM} ${NAME}

re: fclean all
	
.PHONY: all clean fclean re .c.o
