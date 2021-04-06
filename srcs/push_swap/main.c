/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:40:13 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/06 10:15:05 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_stack(t_game *game)
{
	if (stack_size(game->stack_a) == 3)
		sort_3(game, game->stack_a);
	else if (stack_size(game->stack_a) == 5)
		sort_5(game);
	else
		sort(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 1)
		exit_error("Please specify a list of numbers.");
	parse_input(ac, av, &game);
	reverse_stack(game.stack_b, game.stack_a);
	init_map(&game);
	set_indexes(&game);
	if (!is_stack_sorted(game.stack_a))
		sort_stack(&game);
}
