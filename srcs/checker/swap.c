/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:09:50 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/26 12:15:59 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_swap(t_stack *stack)
{
	int	top;
	int	prev;

	top = stack_pop(stack);
	prev = stack_pop(stack);
	stack_push(stack, top);
	stack_push(stack, prev);
}

void	stack_ss(t_stack *stack, t_stack *stack2)
{
	stack_swap(stack);
	stack_swap(stack2);
}
