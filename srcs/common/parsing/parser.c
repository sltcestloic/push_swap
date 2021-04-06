/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:31:56 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/02 12:57:38 by lbertran         ###   ########lyon.fr   */
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
	int		i;

	(void)ac;
	split = ft_split(av[1], ' ');
	i = 0;
	game->stack_a = new_stack(splitlen(split));
	game->stack_b = new_stack(splitlen(split));
	while (split[i])
	{
		if (ft_strcmp("-v", split[i]) == 0 || ft_strcmp("-c", split[i]) == 0)
		{
			if (!game->verbose)
				game->verbose = ft_strcmp("-v", split[i]) == 0;
			if (!game->color)
				game->color = ft_strcmp("-c", split[i]) == 0;
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

int	contains_input(int buffer[], int input, int n)
{
	int	i;

	i = 0;
	while (i < n)
		if (buffer[i++] == input)
			return (TRUE);
	return (FALSE);
}

void	validate_input(t_game *game)
{
	int	head;
	int	*buffer;
	int	i;

	head = game->stack_b->head;
	buffer = malloc(sizeof(int) * (game->stack_b->head + 1));
	if (!buffer)
		return ;
	i = 0;
	while (game->stack_b->head >= 0)
	{
		if (contains_input(buffer, stack_peek(game->stack_b), i))
			exit_error("Duplicate value in input.");
		buffer[i++] = stack_pop(game->stack_b);
	}
	game->stack_b->head = head;
	free(buffer);
}

void	parse_input(int ac, char **av, t_game *game)
{
	if (ac > 2)
		parse_normal_input(ac, av, game);
	else
		parse_char_input(ac, av, game);
	validate_input(game);
}
