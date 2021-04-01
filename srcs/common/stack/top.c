/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:43:47 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/01 13:56:24 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	actions_to_top(t_stack *stack, int index)
{
	int	middle;
	int	ret;
	int	size;

	size = stack_size(stack) - 1;
	middle = size / 2;
	if (index >= middle)
		ret = size - index;
	else
		ret = index + 1;
	return (ret);
}

void	push_to_top_a(t_stack *stack, int index)
{
	int	actions;

	actions = actions_to_top(stack, index) + 1;
	 if (index >= (stack_size(stack) - 1) / 2)
		while (--actions)
			ps_rotate(stack, "ra");
	else
		while (--actions)
			ps_rrotate(stack, "rra");
}

void	push_to_top_b(t_stack *stack, int index)
{
	int	actions;

	actions = actions_to_top(stack, index) + 1;
	 if (index >= (stack_size(stack) - 1) / 2)
		while (--actions)
			ps_rotate(stack, "rb");
	else
		while (--actions)
			ps_rrotate(stack, "rrb");
}
