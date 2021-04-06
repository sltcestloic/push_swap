/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:43:47 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/02 13:38:46 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	actions_to_top(t_stack *stack, int index, int size)
{
	int	middle;
	int	ret;

	(void)stack;
	middle = size / 2;
	if (index >= middle)
		ret = size - index;
	else
		ret = index + 1;
	return (ret);
}

void	push_to_top_a(t_game *game, t_stack *stack, int index)
{
	int	actions;

	actions = actions_to_top(stack, index, stack->head) + 1;
	if (index >= (stack_size(stack) - 1) / 2)
		while (--actions)
			ps_rotate(game, stack, "ra");
	else
		while (--actions)
			ps_rrotate(game, stack, "rra");
}

void	push_to_top_b(t_game *game, t_stack *stack, int index)
{
	int	actions;

	actions = actions_to_top(stack, index, stack->head) + 1;
	 if (index >= (stack_size(stack) - 1) / 2)
		while (--actions)
			ps_rotate(game, stack, "rb");
	else
		while (--actions)
			ps_rrotate(game, stack, "rrb");
}
