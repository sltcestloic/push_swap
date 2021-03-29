/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:09:46 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/29 15:25:41 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	find_median(t_stack *stack, int mid)
{
	int	ret;
	int	diff;
	int	head;

	head = stack->head;
	diff = INT_MAX;
	while (stack->head >= 0)
	{
		if (ft_abs(stack_peek(stack) - mid) < diff)
		{
			diff = ft_abs(stack_peek(stack) - mid);
			ret = stack->head;
		}
		stack->head--;
	}
	stack->head = head;
	return (ret);
}

void	sort(t_game *game)
{
	int	smallest;
	int	biggest;
	int	median;
	int	current;
	

	smallest = stack_smallest(game->stack_a);
	biggest = stack_biggest(game->stack_a);
	median = find_median(game->stack_a, biggest / 2);
	current = stack_get(game->stack_a, median);
	/* int	bigger = find_next_bigger(game->stack_a, current);
	int	smaller = find_next_smaller(game->stack_a, current);
	printf("median: %d\n", current);
	printf("next smaller: %d\n", stack_get(game->stack_a, smaller));
	printf("next bigger: %d\n", stack_get(game->stack_a, bigger)); */
	push_to_top(game->stack_a, median);
	ps_push(game->stack_a, game->stack_b, "pb");
	while (!is_empty(game->stack_a))
	{
		push_to_top(game->stack_a, find_next(game->stack_a, current));
		if (stack_peek(game->stack_a) > stack_peek(game->stack_b))
		{
			ps_push(game->stack_a, game->stack_b, "pb");
			current = stack_peek(game->stack_b);
		}
		else
		{
			ps_push(game->stack_a, game->stack_b, "pb");
			ps_rotate(game->stack_b, "rb");
		}
	}
	while (!is_empty(game->stack_b))
		ps_push(game->stack_b, game->stack_a, "pa");
	print_game(game);
}