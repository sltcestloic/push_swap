/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:23:45 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/16 16:46:06 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

t_stack	*new_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit_error("Failed to malloc stack.");
	stack->capacity = capacity;
	stack->head = -1;
	stack->content = (int *)malloc(sizeof(int) * capacity);
	if (!stack->capacity)
		exit_error("Failed to malloc stack capacity.");
	return (stack);
}

int	stack_size(t_stack *stack)
{
	return (stack->head + 1);
}

void	stack_push(t_stack *stack, int val)
{
	
}