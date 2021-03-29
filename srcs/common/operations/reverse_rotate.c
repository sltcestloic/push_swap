/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:39:28 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/29 13:33:10 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ps_rrotate(t_stack *stack, char *msg)
{
	t_stack *copy;
	int	swap;
	int	head;

	if (msg)
		printf("%s\n", msg);
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
	free(copy->content);
	free(copy);
}

void	ps_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ps_rrotate(stack_a, "rra");
	ps_rrotate(stack_b, "rrb");
}
