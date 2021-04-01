/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:50:30 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/01 13:50:38 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	stack_peek(t_stack *stack)
{
	if (is_empty(stack))
		exit_error("Tried to peek element from empty stack.");
	return (stack->content[stack->head]);
}

int	stack_pop(t_stack *stack)
{
	if (is_empty(stack))
		exit_error("Tried to pop element from empty stack.");
	return (stack->content[stack->head--]);
}
