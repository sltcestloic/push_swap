/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:45:37 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/28 15:54:29 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ps_rotate(t_stack *stack, char *msg)
{
	t_stack *copy;
	int		head;

	if (msg)
		printf("%s\n", msg);
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
}

void	ps_rr(t_stack *stack_a, t_stack *stack_b)
{
	ps_rotate(stack_a, "ra");
	ps_rotate(stack_b, "rb");
}
