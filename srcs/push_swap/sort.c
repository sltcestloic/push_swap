/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:09:46 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/31 13:56:43 by lbertran         ###   ########lyon.fr   */
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

int	find_median_value(t_stack *stack, int mid)
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
			ret = stack_peek(stack);
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
	
	smallest = stack_smallest(game->stack_b);
	biggest = stack_biggest(game->stack_b);
	median = find_median(game->stack_b, biggest / 2);
	current = stack_peek(game->stack_a);
	while (!is_empty(game->stack_b))
	{
		push_to_top_b(game->stack_b, find_next(game->stack_b, current));
		if (stack_peek(game->stack_b) < stack_peek(game->stack_a))
		{
			ps_push(game->stack_b, game->stack_a, "pa");
			current = stack_peek(game->stack_a);
		}
		else
		{
			ps_push(game->stack_b, game->stack_a, "pa");
			ps_rotate(game->stack_a, "ra");
		}
	}
	//print_game(game);
}

int	find_in_range(t_stack *stack, int smallest, int chunk_size, int step, int median)
{
	int	ret;
	int	diff;
	int	head;
	int	min;
	int	max;

	head = stack->head;
	diff = INT_MAX;
	ret = INT_MAX;
	if (step > 1)
		min = chunk_size * (step - 1) + 2;
	else 
		min = smallest + chunk_size * (step - 1);
	max = chunk_size * step + 1;
	//printf("range: %d %d\n", min, max);
	while (stack->head >= 0)
	{
		if (stack_peek(stack) >= min && stack_peek(stack) <= max && stack_peek(stack) != median)
		{
			if (actions_to_top(stack, stack->head) < diff)
			{
				diff = actions_to_top(stack, stack->head);
				ret = stack->head;
			}
		}
		stack->head--;
	}
	//printf("found %d %d\n", ret, diff);
	stack->head = head;
	return (ret);
}

void	sort_loop(t_game *game, int smallest, int chunk_size, int step, int median)
{
	int	current;
	while (stack_size(game->stack_a) > 1)
	{
		current = find_in_range(game->stack_a, smallest, chunk_size, step, median);
		if (current == INT_MAX)
		{
			step++;
			if (step > 4)
				break ;
			continue;
		}
		push_to_top_a(game->stack_a, current);
		if (is_empty(game->stack_b))
		{
			ps_push(game->stack_a, game->stack_b, "pb");
			continue;
		}
		if (stack_peek(game->stack_a) < stack_get(game->stack_b, 0))
		{
			ps_push(game->stack_a, game->stack_b, "pb");
			ps_rotate(game->stack_b, "rb");
		}
		else if (stack_peek(game->stack_a) < stack_peek(game->stack_b))
		{
			ps_push(game->stack_a, game->stack_b, "pb");
			ps_swap(game->stack_b, "sb");
		}
		else
			ps_push(game->stack_a, game->stack_b, "pb");
	}
	//print_game(game);
	//sort(game);
}

void	newsort(t_game *game)
{
	int	smallest;
	int	biggest;
	int	median;
	int	step;
	int	chunk_size;

	smallest = stack_smallest(game->stack_a);
	biggest = stack_biggest(game->stack_a);
	median = find_median_value(game->stack_a, biggest / 2);
	step = 1;
	chunk_size = biggest / 4;
	//printf("smallest %d biggest %d median %d chunk_size %d\n", smallest, biggest, median, chunk_size);
	sort_loop(game, smallest, chunk_size, step, median);
}