/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:48:24 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/02 13:13:55 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

char	*get_color(int val, t_game *game)
{
	if (!game->color)
		return (RESET);
	else if (val == game->swap_a && game->swapped)
		return (HRED);
	else if (val == game->swap_b && game->swapped)
		return (YELLOW);
	else if (val == game->pushed_nbr && game->pushed)
		return (GREEN);
	else if (val == game->rotated_nbr && game->rotated)
		return (HBLUE);
	else
		return (RESET);
}
