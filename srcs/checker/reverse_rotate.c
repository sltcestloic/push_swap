/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:39:28 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/26 16:45:32 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ps_rrotate(t_stack *stack, char *msg)
{
	t_stack *copy;

	printf("%s\n", msg);
	copy = stack_copy(stack);
	stack->head = copy->head - 1;
	copy->head = 0;
	stack_push(stack, stack_pop(copy));
	copy->head = 1;
	stack->head = -1;
	while (copy->head < copy->capacity)
	{
		stack_push(stack, stack_peek(copy));
		copy->head++;
	}
	stack->head = copy->head - 1;
}

void	ps_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ps_rrotate(stack_a, "rra");
	ps_rrotate(stack_b, "rrb");
}