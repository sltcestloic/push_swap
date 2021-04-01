/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:13:02 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/01 14:13:12 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	find_median(t_stack *stack, int mid)
{
	int	ret;
	int	diff;
	int	head;

	head = stack->head;
	diff = INT_MAX;
	while (stack->head >= 0)
	{
		if (ft_abs(stack_peek(stack) - mid) < diff)
		{
			diff = ft_abs(stack_peek(stack) - mid);
			ret = stack->head;
		}
		stack->head--;
	}
	stack->head = head;
	return (ret);
}

int	find_median_value(t_stack *stack, int mid)
{
	int	ret;
	int	diff;
	int	head;

	head = stack->head;
	diff = INT_MAX;
	while (stack->head >= 0)
	{
		if (ft_abs(stack_peek(stack) - mid) < diff)
		{
			diff = ft_abs(stack_peek(stack) - mid);
			ret = stack_peek(stack);
		}
		stack->head--;
	}
	stack->head = head;
	return (ret);
}
