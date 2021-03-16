/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:40:58 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/16 16:55:34 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"


typedef struct	s_stack
{
	int			capacity;
	int			head;
	int			*content;
}				t_stack;


void	exit_error(char *message);
void	print_error(char *message);

t_stack	*new_stack(int capacity);
int		stack_size(t_stack *stack);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
void	stack_push(t_stack *stack, int val);
int		stack_peek(t_stack *stack);
int		stack_pop(t_stack *stack);

#endif
