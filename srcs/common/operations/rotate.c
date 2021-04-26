/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:45:37 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/26 15:30:06 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ps_rotate(t_game *game, t_stack *stack, char *msg)
{
	t_stack	*copy;
	int		head;

	if (msg)
		printf("%s\n", msg);
	if (is_empty(stack))
		return ;
	copy = stack_copy(stack);
	head = stack->head;
	stack->head = -1;
	stack_push(stack, stack_pop(copy));
	copy->head = 0;
	while (copy->head < head)
	{
		stack_push(stack, stack_peek(copy));
		copy->head++;
	}
	game->rotated = TRUE;
	game->rotated_nbr = stack_get(stack, 0);
}

void	ps_rr(t_game *game, t_stack *stack_a, t_stack *stack_b)
{
	ps_rotate(game, stack_a, "ra");
	ps_rotate(game, stack_b, "rb");
}
