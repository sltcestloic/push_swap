/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:09:50 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/28 15:54:39 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ps_swap(t_stack *stack, char *msg)
{
	int	top;
	int	prev;

	if (msg)
		printf("%s\n", msg);
	top = stack_pop(stack);
	prev = stack_pop(stack);
	stack_push(stack, top);
	stack_push(stack, prev);
}

void	ps_ss(t_stack *stack_a, t_stack *stack_b)
{
	ps_swap(stack_a, "sa");
	ps_swap(stack_b, "sb");
}
