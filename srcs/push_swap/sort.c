/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:09:46 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/01 14:17:19 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_to_a(t_game *game)
{
	int	smallest;
	int	biggest;
	int	median;
	int	current;

	smallest = stack_smallest(game->stack_b);
	biggest = stack_biggest(game->stack_b);
	median = find_median(game->stack_b, biggest / 2);
	current = stack_peek(game->stack_a);
	while (!is_empty(game->stack_b))
	{
		push_to_top_b(game->stack_b, stack_biggest_index(game->stack_b));
		if (stack_peek(game->stack_b) < stack_peek(game->stack_a))
		{
			ps_push(game->stack_b, game->stack_a, "pa");
			current = stack_peek(game->stack_a);
		}
		else
		{
			ps_push(game->stack_b, game->stack_a, "pa");
			ps_rotate(game->stack_a, "ra");
		}
	}
}

static void	loop_norm(t_game *game)
{
	if (stack_peek(game->stack_a) < stack_get(game->stack_b, 0))
	{
		ps_push(game->stack_a, game->stack_b, "pb");
		ps_rotate(game->stack_b, "rb");
	}
	else if (stack_peek(game->stack_a) < stack_peek(game->stack_b))
	{
		ps_push(game->stack_a, game->stack_b, "pb");
		ps_swap(game->stack_b, "sb");
	}
	else
		ps_push(game->stack_a, game->stack_b, "pb");
}

void	sort_loop(t_game *game)
{
	int	current;

	while (stack_size(game->stack_a) > 1)
	{
		current = find_in_range(game->stack_a, game);
		if (current == INT_MAX)
		{
			game->step++;
			continue ;
		}
		push_to_top_a(game->stack_a, current);
		if (is_empty(game->stack_b))
		{
			ps_push(game->stack_a, game->stack_b, "pb");
			continue ;
		}
		loop_norm(game);
	}
	print_game(game);
	sort_to_a(game);
}

void	sort(t_game *game)
{
	game->smallest = stack_smallest(game->stack_a);
	game->biggest = stack_biggest(game->stack_a);
	game->median = find_median_value(game->stack_a, game->biggest / 2);
	game->step = 1;
	game->chunk_size = get_ideal_chunk_size(game, game->biggest);
	sort_loop(game);
}
