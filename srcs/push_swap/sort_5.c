/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:38:33 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/29 13:53:46 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_5(t_game *game)
{
	int	min;
	int	max;

	min = stack_smallest_index(game->stack_a);
	max = stack_biggest_index(game->stack_a);
	//print_game(game);
	//printf("index de %d : %d\n", stack_smallest(game->stack_a), min);
	//printf("actions min: %d\n", actions_to_top(game->stack_a, min));
	//printf("index de %d : %d\n", stack_biggest(game->stack_a), max);
	//printf("actions max: %d\n", actions_to_top(game->stack_a, max));
	if (actions_to_top(game->stack_a, min) < actions_to_top(game->stack_a, max))
	{
		push_to_top(game->stack_a, min);
		//print_game(game);
		ps_push(game->stack_a, game->stack_b, "pb");
		push_to_top(game->stack_a, stack_biggest_index(game->stack_a));
		//print_game(game);
	}
	else
	{
		push_to_top(game->stack_a, max);
		//print_game(game);
		ps_push(game->stack_a, game->stack_b, "pb");
		//print_game(game);
		//printf("actions pr push index %d : %d\n", stack_smallest_index(game->stack_a), actions_to_top(game->stack_a, stack_smallest_index(game->stack_a)));
		push_to_top(game->stack_a, stack_smallest_index(game->stack_a));
		//print_game(game);
	}
	ps_push(game->stack_a, game->stack_b, "pb");
	//print_game(game);
	if (!is_stack_sorted(game->stack_a))
		sort_3(game->stack_a);
	//print_game(game);
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
	//print_game(game);
}