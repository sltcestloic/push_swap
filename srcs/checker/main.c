/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:42:09 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/26 15:26:51 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reset_action(t_game *game)
{
	game->pushed_nbr = -1;
	game->swap_a = -1;
	game->swap_b = -1;
	game->rotated_nbr = -1;
	game->pushed = FALSE;
	game->swapped = FALSE;
	game->rotated = FALSE;
}

static void	free_stacks(t_game *game)
{
	free(game->stack_a->content);
	free(game->stack_b->content);
	free(game->stack_a);
	free(game->stack_b);
}

void	handle_entry(char *line, t_game *game)
{
	reset_action(game);
	if (ft_strcmp("sa", line) == 0)
		ps_swap(game, game->stack_a, NULL);
	else if (ft_strcmp("sb", line) == 0)
		ps_swap(game, game->stack_b, NULL);
	else if (ft_strcmp("ss", line) == 0)
		ps_ss(game, game->stack_a, game->stack_b);
	else if (ft_strcmp("pa", line) == 0)
		ps_push(game, game->stack_b, game->stack_a, NULL);
	else if (ft_strcmp("pb", line) == 0)
		ps_push(game, game->stack_a, game->stack_b, NULL);
	else if (ft_strcmp("ra", line) == 0)
		ps_rotate(game, game->stack_a, NULL);
	else if (ft_strcmp("rb", line) == 0)
		ps_rotate(game, game->stack_b, NULL);
	else if (ft_strcmp("rr", line) == 0)
		ps_rr(game, game->stack_a, game->stack_b);
	else if (ft_strcmp("rra", line) == 0)
		ps_rrotate(game, game->stack_a, NULL);
	else if (ft_strcmp("rrb", line) == 0)
		ps_rrotate(game, game->stack_b, NULL);
	else if (ft_strcmp("rrr", line) == 0)
		ps_rrr(game, game->stack_a, game->stack_b);
	else
		exit_error("Invalid action.");
}

int	main(int ac, char **av)
{
	t_game	game;
	char	*line;

	if (ac == 1)
		exit_error("Please specify a list of numbers.");
	game.verbose = FALSE;
	game.color = FALSE;
	reset_action(&game);
	parse_input(ac, av, &game);
	reverse_stack(game.stack_b, game.stack_a);
	if (game.verbose)
		print_game(&game);
	while (ft_get_next_line(0, &line))
	{
		handle_entry(line, &game);
		free(line);
		if (game.verbose)
			print_game(&game);
	}
	free(line);
	if (is_stack_sorted(game.stack_a) && is_empty(game.stack_b))
		printf("%sOK%s\n", GREEN, RESET);
	else
		fprintf(stderr, "%sKO%s\n", RED, RESET);
	free_stacks(&game);
}
