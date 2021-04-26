/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:39:28 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/26 15:30:09 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ps_rrotate(t_game *game, t_stack *stack, char *msg)
{
	t_stack	*copy;
	int		swap;
	int		head;

	if (msg)
		printf("%s\n", msg);
	if (is_empty(stack))
		return ;
	head = stack->head;
	copy = new_stack(stack->capacity);
	while (copy->head < head)
		stack_push(copy, stack_pop(stack));
	swap = stack_pop(copy);
	stack->head = -1;
	while (copy->head >= 0)
		stack_push(stack, stack_pop(copy));
	stack_push(stack, swap);
	stack->head = head;
	game->rotated = TRUE;
	game->rotated_nbr = stack_peek(stack);
	free(copy->content);
	free(copy);
}

void	ps_rrr(t_game *game, t_stack *stack_a, t_stack *stack_b)
{
	ps_rrotate(game, stack_a, "rra");
	ps_rrotate(game, stack_b, "rrb");
}
