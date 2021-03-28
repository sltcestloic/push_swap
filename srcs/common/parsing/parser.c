/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:31:56 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/28 15:17:02 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	parse_normal_input(int ac, char **av, t_game *game)
{
	int	i;

	i = 1;
	game->stack_a = new_stack(ac - 1);
	game->stack_b = new_stack(ac - 1);
	while (i < ac)
	{
		if (ft_strcmp("-v", av[i]) == 0)
		{
			game->verbose = TRUE;
			i++;
			continue ;
		}
		if (ft_atoi(av[i]) == 0 && ft_strcmp("0", av[i]) != 0)
			exit_error("Invalid argument.");
		stack_push(game->stack_b, ft_atoi(av[i]));
		i++;
	}
}

void	parse_char_input(int ac, char **av, t_game *game)
{
	char	**split;
	int	i;

	(void)ac;
	split = ft_split(av[1], ' ');
	i = 0;
	game->stack_a = new_stack(splitlen(split));
	game->stack_b = new_stack(splitlen(split));
	while (split[i])
	{
		if (ft_strcmp("-v", split[i]) == 0)
		{
			game->verbose = TRUE;
			i++;
			continue ;
		}
		if (ft_atoi(split[i]) == 0 && ft_strcmp("0", split[i]) != 0)
			exit_error("Invalid argument.");
		stack_push(game->stack_b, ft_atoi(split[i]));
		i++;
	}
	free_split(split);
}

void	parse_input(int ac, char **av, t_game *game)
{
	
	if (ac > 2)
		parse_normal_input(ac, av, game);
	else
		parse_char_input(ac, av, game);
}
