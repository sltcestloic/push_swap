/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:49:48 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/06 10:06:39 by lbertran         ###   ########lyon.fr   */
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
	if (!stack->content)
		exit_error("Failed to malloc stack content.");
	return (stack);
}

int	stack_size(t_stack *stack)
{
	return (stack->head + 1);
}

int	is_full(t_stack *stack)
{
	return (stack->head == stack->capacity - 1);
}

int	is_empty(t_stack *stack)
{
	return (stack_size(stack) == 0);
}

void	stack_push(t_stack *stack, int val)
{
	if (is_full(stack))
		exit_error("Tried to add element to full stack.");
	stack->content[++stack->head] = val;
}
