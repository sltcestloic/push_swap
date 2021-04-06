/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:43:01 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/02 13:13:13 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ps_push(t_game *game, t_stack *origin, t_stack *destination, char *msg)
{
	int	val;

	if (msg)
		printf("%s\n", msg);
	val = stack_pop(origin);
	game->pushed_nbr = val;
	game->pushed = TRUE;
	stack_push(destination, val);
}
