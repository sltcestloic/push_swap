/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 09:56:52 by lbertran          #+#    #+#             */
/*   Updated: 2021/05/13 13:40:18 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	map_put(t_game *game, int key, int value)
{
	if (game->map->index >= game->map->capacity)
		exit_error("Tried to add element to full map.");
	game->map->key[game->map->index] = key;
	game->map->value[game->map->index] = value;
	game->map->index++;
}

int	map_get(t_game *game, int key)
{
	int	i;

	i = 0;
	while (i < game->map->capacity)
	{
		if (game->map->key[i] == key)
			return (game->map->value[i]);
		i++;
	}
	return (-1);
}

void	init_map(t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_error("Failed to malloc map.");
	map->capacity = game->stack_a->capacity;
	map->key = malloc(sizeof(int) * map->capacity);
	if (!map->key)
		exit_error("Failed to malloc map key array.");
	map->value = malloc(sizeof(int) * map->capacity);
	if (!map->value)
		exit_error("Failed to malloc map value array.");
	map->index = 0;
	game->map = map;
}

void	set_indexes(t_game *game)
{
	t_stack	*copy;

	copy = stack_copy(game->stack_a);
	while (!is_empty(copy))
	{
		push_to_top_silent(game, copy, stack_biggest_index(copy));
		map_put(game, stack_pop(copy), game->map->index);
	}
	free(copy->content);
	free(copy);
}
