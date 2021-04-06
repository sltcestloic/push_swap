/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:17:02 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/06 10:31:28 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	init_range(t_range *range, t_game *game)
{
	if (game->step > 1)
		range->min = game->chunk_size * (game->step - 1) + 2;
	else
		range->min = 0;
	range->max = game->chunk_size * game->step + 1;
}

static int	get_index(t_game *game, t_stack *stack)
{
	return (map_get(game, stack_peek(stack)));
}

int	find_in_range(t_stack *stack, t_game *game)
{
	int		ret;
	int		diff;
	int		head;
	t_range	range;

	head = stack->head;
	diff = INT_MAX;
	ret = INT_MAX;
	init_range(&range, game);
	while (stack->head >= 0)
	{
		if (get_index(game, stack) >= range.min && get_index(game, stack) <= range.max
			&& stack_peek(stack) != game->biggest)
		{
			if (actions_to_top(stack, stack->head, head) < diff)
			{
				diff = actions_to_top(stack, stack->head, head);
				ret = stack->head;
			}
		}
		stack->head--;
	}
	stack->head = head;
	return (ret);
}
