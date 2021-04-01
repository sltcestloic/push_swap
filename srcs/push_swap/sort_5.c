/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:38:33 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/01 14:11:44 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	norm(t_game *game)
{
	if (!is_stack_sorted(game->stack_a))
		sort_3(game->stack_a);
	if (stack_peek(game->stack_b) > stack_peek(game->stack_a))
	{
		ps_push(game->stack_b, game->stack_a, "pa");
		ps_rotate(game->stack_a, "ra");
		ps_push(game->stack_b, game->stack_a, "pa");
	}
	else
	{
		ps_push(game->stack_b, game->stack_a, "pa");
		ps_push(game->stack_b, game->stack_a, "pa");
		ps_rotate(game->stack_a, "ra");
	}
}

void	sort_5(t_game *game)
{
	int	min;
	int	max;

	min = stack_smallest_index(game->stack_a);
	max = stack_biggest_index(game->stack_a);
	if (actions_to_top(game->stack_a, min) < actions_to_top(game->stack_a, max))
	{
		push_to_top_a(game->stack_a, min);
		ps_push(game->stack_a, game->stack_b, "pb");
		push_to_top_a(game->stack_a, stack_biggest_index(game->stack_a));
	}
	else
	{
		push_to_top_a(game->stack_a, max);
		ps_push(game->stack_a, game->stack_b, "pb");
		push_to_top_a(game->stack_a, stack_smallest_index(game->stack_a));
	}
	ps_push(game->stack_a, game->stack_b, "pb");
	norm(game);
}
