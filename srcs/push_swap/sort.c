/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:09:46 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/29 12:37:28 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_in_range(t_stack *stack, int min, int max)
{
	int	head;
	int	ret;
	int	actions;

	head = stack->head;
	actions = INT_MAX;
	while (stack->head >= 0)
	{
		if (stack_peek(stack) >= min && stack_peek(stack_peek) <= max)
			if (actions_to_top(stack_peek(stack), stack->head) < actions)
			{
				actions = actions_to_top(stack_peek(stack), stack->head);
				ret = stack->head;
			}
	}
	stack->head = head;
	return (ret);
}

void	sort(t_game *game)
{
	int	smallest;
	int	biggest;

	smallest = stack_smallest(game->stack_a);
	biggest = stack_biggest(game->stack_a);
}