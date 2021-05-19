/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:31:56 by lbertran          #+#    #+#             */
/*   Updated: 2021/05/19 12:53:09 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	parse_normal_input(int ac, char **av, t_game *game)
{
	int		i;
	char	*itoa;

	i = 0;
	game->stack_a = new_stack(ac - 1);
	game->stack_b = new_stack(ac - 1);
	while (++i < ac)
	{
		itoa = ft_itoa(ft_atoi(av[i]));
		if (ft_strcmp("-v", av[i]) == 0 || ft_strcmp("-c", av[i]) == 0)
		{
			if (!game->verbose)
				game->verbose = ft_strcmp("-v", av[i]) == 0;
			if (!game->color)
				game->color = ft_strcmp("-c", av[i]) == 0;
			i++;
			free(itoa);
			continue ;
		}
		if (ft_strcmp(itoa, av[i]) != 0
			&& ft_strcmp("-2147483648", av[i]) != 0)
			exit_error("Invalid argument.");
		stack_push(game->stack_b, ft_atoi(av[i]));
		free(itoa);
	}
}

void	parse_char_input(char **av, t_game *game)
{
	char	**split;
	char	*itoa;
	int		i;

	split = ft_split(av[1], ' ');
	i = -1;
	game->stack_a = new_stack(splitlen(split));
	game->stack_b = new_stack(splitlen(split));
	while (split[++i])
	{
		itoa = ft_itoa(ft_atoi(split[i]));
		if (ft_strcmp(itoa, split[i]) != 0
			&& ft_strcmp("-2147483648", split[i]) != 0)
			exit_error("Invalid argument.");
		stack_push(game->stack_b, ft_atoi(split[i]));
		free(itoa);
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
		parse_char_input(av, game);
	validate_input(game);
}
