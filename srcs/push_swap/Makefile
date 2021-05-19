# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:40:32 by lbertran          #+#    #+#              #
#    Updated: 2021/05/19 12:28:58 by lbertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC		= main.c \
			sort_3.c \
			sort_5.c \
			sort.c
OBJS	= ${SRC:.c=.o}
INCS	= includes
NAME	= push_swap
LIBC	= ar rcs
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g3 -O3

%.o: %.c ${INCS} ../../libft/libft.a ../common/common.a
	${CC} ${CFLAGS} -c $< -o $@ -I${INCS}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS} ../../libft/libft.a ../common/common.a
	
all: ${NAME}

bonus: all

clean:
	${RM} ${OBJS}
	${RM} a.out

fclean: clean
	${RM} ${NAME}

re: fclean all
	
.PHONY: all clean fclean re .c.o
