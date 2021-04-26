/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:09:50 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/26 15:29:50 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ps_swap(t_game *game, t_stack *stack, char *msg)
{
	int	top;
	int	prev;

	if (msg)
		printf("%s\n", msg);
	if (is_empty(stack))
		return ;
	top = stack_pop(stack);
	prev = stack_pop(stack);
	game->swap_a = top;
	game->swap_b = prev;
	game->swapped = TRUE;
	stack_push(stack, top);
	stack_push(stack, prev);
}

void	ps_ss(t_game *game, t_stack *stack_a, t_stack *stack_b)
{
	ps_swap(game, stack_a, "sa");
	ps_swap(game, stack_b, "sb");
}
