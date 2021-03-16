/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:23:45 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/16 16:54:09 by lbertran         ###   ########lyon.fr   */
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

int	stack_peek(t_stack *stack)
{
	if (is_empty(stack))
		exit_error("Tried to peek element from empty stack.");
	return (stack->content[stack->head]);
}

int	stack_pop(t_stack *stack)
{
	if (is_empty(stack))
		exit_error("Tried to pop element from empty stack.");
	return (stack->content[stack->head--]);
}