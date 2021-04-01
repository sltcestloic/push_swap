/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:44:38 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/01 13:55:34 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	find_next_bigger(t_stack *stack, int current)
{
	int	ret;
	int	diff;
	int	head;

	head = stack->head;
	diff = INT_MIN;
	if (stack_size(stack) == 1)
		return (stack->head);
	while (stack->head >= 0)
	{
		if (current - stack_peek(stack) < 0 && current
			- stack_peek(stack) > diff)
		{
			diff = current - stack_peek(stack);
			ret = stack->head;
		}
		stack->head--;
	}
	stack->head = head;
	if (diff == INT_MIN)
		return (-1);
	return (ret);
}

int	find_next_smaller(t_stack *stack, int current)
{
	int	ret;
	int	diff;
	int	head;

	head = stack->head;
	diff = INT_MAX;
	if (stack_size(stack) == 1)
		return (stack->head);
	while (stack->head >= 0)
	{
		if (current - stack_peek(stack) > 0 && current
			- stack_peek(stack) < diff)
		{
			diff = current - stack_peek(stack);
			ret = stack->head;
		}
		stack->head--;
	}
	stack->head = head;
	if (diff == INT_MAX)
		return (-1);
	return (ret);
}

int	find_next(t_stack *stack, int current)
{
	int	bigger;
	int	smaller;

	bigger = find_next_bigger(stack, current);
	smaller = find_next_smaller(stack, current);
	if (bigger == -1)
		return (smaller);
	else if (smaller == -1)
		return (bigger);
	if (actions_to_top(stack, bigger) < actions_to_top(stack, smaller))
		return (bigger);
	else
		return (smaller);
}
