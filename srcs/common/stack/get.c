/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:45:55 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/01 13:55:12 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	stack_smallest(t_stack *stack)
{
	int	ret;
	int	head;

	ret = INT_MAX;
	head = stack->head;
	while (stack->head >= 0)
	{
		if (stack_peek(stack) < ret)
			ret = stack_peek(stack);
		stack->head--;
	}
	stack->head = head;
	return (ret);
}

int	stack_smallest_index(t_stack *stack)
{
	int	ret;
	int	head;
	int	val;

	val = INT_MAX;
	head = stack->head;
	while (stack->head >= 0)
	{
		if (stack_peek(stack) < val)
		{
			val = stack_peek(stack);
			ret = stack->head;
		}
		stack->head--;
	}
	stack->head = head;
	return (ret);
}

int	stack_biggest(t_stack *stack)
{
	int	ret;
	int	head;

	ret = INT_MIN;
	head = stack->head;
	while (stack->head >= 0)
	{
		if (stack_peek(stack) > ret)
			ret = stack_peek(stack);
		stack->head--;
	}
	stack->head = head;
	return (ret);
}

int	stack_biggest_index(t_stack *stack)
{
	int	ret;
	int	head;
	int	val;

	val = INT_MIN;
	head = stack->head;
	while (stack->head >= 0)
	{
		if (stack_peek(stack) > val)
		{
			val = stack_peek(stack);
			ret = stack->head;
		}
		stack->head--;
	}
	stack->head = head;
	return (ret);
}

int	stack_get(t_stack *stack, int head)
{
	int	head_prev;
	int	ret;

	head_prev = stack->head;
	stack->head = head;
	ret = stack_peek(stack);
	stack->head = head_prev;
	return (ret);
}
