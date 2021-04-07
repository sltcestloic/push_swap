# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:40:32 by lbertran          #+#    #+#              #
#    Updated: 2021/04/07 15:02:12 by lbertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

all:
	@${MAKE} -C ./libft	
	@${MAKE} -C ./srcs/common
	@${MAKE} -C ./srcs/push_swap
	@${MAKE} -C ./srcs/checker
	@cp srcs/checker/checker ./checker
	@cp srcs/push_swap/push_swap ./push_swap

clean:
	@${MAKE} clean -C ./libft
	@${MAKE} clean -C ./srcs/common
	@${MAKE} clean -C ./srcs/push_swap
	@${MAKE} clean -C ./srcs/checker

fclean: clean
	@${MAKE} fclean -C ./libft
	@${MAKE} fclean -C ./srcs/common
	@${MAKE} fclean -C ./srcs/push_swap
	@${MAKE} fclean -C ./srcs/checker
	@rm checker
	@rm push_swap

re: fclean all
	
.PHONY: all clean fclean re .c.o
