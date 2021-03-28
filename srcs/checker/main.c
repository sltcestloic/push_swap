/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:42:09 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/28 15:23:10 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	handle_entry(char *line, t_game *game)
{
	if (ft_strcmp("sa", line) == 0)
		ps_swap(game->stack_a, "sa");
	else if (ft_strcmp("sb", line) == 0)
		ps_swap(game->stack_b, "sb");
	else if (ft_strcmp("ss", line) == 0)
		ps_ss(game->stack_a, game->stack_b);
	else if (ft_strcmp("pa", line) == 0)
		ps_push(game->stack_b, game->stack_a, "pa");
	else if (ft_strcmp("pb", line) == 0)
		ps_push(game->stack_a, game->stack_b, "pb");
	else if (ft_strcmp("ra", line) == 0)
		ps_rotate(game->stack_a, "ra");
	else if (ft_strcmp("rb", line) == 0)
		ps_rotate(game->stack_b, "rb");
	else if (ft_strcmp("rr", line) == 0)
		ps_rr(game->stack_a, game->stack_b);
	else if (ft_strcmp("rra", line) == 0)
		ps_rrotate(game->stack_a, "rra");
	else if (ft_strcmp("rrb", line) == 0)
		ps_rrotate(game->stack_b, "rrb");
	else if (ft_strcmp("rrr", line) == 0)
		ps_rrr(game->stack_a, game->stack_b);
}


/* int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_stack *stack_a = new_stack(6);

	
	stack_push(stack_a, 2);
	stack_push(stack_a, 3);
	stack_push(stack_a, 4);
	stack_push(stack_a, 1);

	printf("%d\n", stack_a->head);
	ps_rotate(stack_a, "rb");
}  */

int	main(int ac, char **av)
{
	t_game	game;
	char	*line;

	if (ac == 1)
		exit_error("Please specify a list of numbers.");
	game.verbose = FALSE;
	parse_input(ac, av, &game);
	reverse_stack(game.stack_b, game.stack_a);
	while (ft_get_next_line(0, &line))
	{
		handle_entry(line, &game);
		free(line);
		if (game.verbose)
			print_game(&game);
	}
	if (is_stack_sorted(game.stack_a) && is_empty(game.stack_b))
		printf("%sOK%s\n", GREEN, RESET);
	else
		fprintf(stderr, "%sKO%s\n", RED, RESET);
}