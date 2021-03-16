# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:40:32 by lbertran          #+#    #+#              #
#    Updated: 2021/03/16 16:40:17 by lbertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC		= error.c
OBJS	= ${SRC:.c=.o}
INCS	= includes
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