/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:42:09 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/26 16:43:30 by lbertran         ###   ########lyon.fr   */
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
	(void)ac;
	(void)av;
	t_game	game;
	t_stack *stack_a = new_stack(6);
	t_stack	*stack_b = new_stack(6);
	char	*line;

	
	stack_push(stack_a, 6);
	stack_push(stack_a, 1);
	stack_push(stack_a, 5);
	stack_push(stack_a, 3);
	stack_push(stack_a, 4);
	stack_push(stack_a, 2);

	game.stack_a = stack_a;
	game.stack_b = stack_b;
	print_game(&game);
	while (ft_get_next_line(0, &line))
	{
		handle_entry(line, &game);
		print_game(&game);
	}
}
