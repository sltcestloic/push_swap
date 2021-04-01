/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:48:52 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/01 14:17:01 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

t_stack	*stack_copy(t_stack *stack)
{
	t_stack	*copy;
	int		head;

	head = stack->head;
	copy = new_stack(stack->capacity);
	stack->head = 0;
	while (stack->head < stack->capacity)
	{
		stack_push(copy, stack_peek(stack));
		stack->head++;
	}
	stack->head = head;
	copy->head = head;
	return (copy);
}

int	is_stack_sorted(t_stack *stack)
{
	int	head;
	int	val;
	int	sorted;

	head = stack->head;
	sorted = TRUE;
	while (stack->head)
	{
		val = stack_pop(stack);
		if (val > stack_peek(stack))
			sorted = FALSE;
	}
	stack->head = head;
	return (sorted);
}

void	reverse_stack(t_stack *tmp, t_stack *stack)
{
	while (tmp->head >= 0)
		stack_push(stack, stack_pop(tmp));
}

int	get_ideal_chunk_size(t_game *game, int biggest)
{
	t_stack	*stack;

	stack = game->stack_a;
	if (stack->capacity < 70)
		return (biggest / 4);
	else if (stack->capacity < 300)
		return (biggest / 8);
	else if (stack->capacity < 400)
		return (biggest / 6);
	else
		return (biggest / 16);
}
