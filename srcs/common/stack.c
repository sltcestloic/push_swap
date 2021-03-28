/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:23:45 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/28 14:58:28 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*new_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit_error("Failed to malloc stack.");
	stack->capacity = capacity;
	stack->head = -1;
	stack->content = (int *)malloc(sizeof(int) * capacity);
	if (!stack->capacity)
		exit_error("Failed to malloc stack capacity.");
	return (stack);
}

int	stack_size(t_stack *stack)
{
	return (stack->head + 1);
}

int	is_full(t_stack *stack)
{
	return (stack->head == stack->capacity - 1);
}

int	is_empty(t_stack *stack)
{
	return (stack_size(stack) == 0);
}

void	stack_push(t_stack *stack, int val)
{
	if (is_full(stack))
		exit_error("Tried to add element to full stack.");
	stack->content[++stack->head] = val;
}

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

t_stack	*stack_copy(t_stack *stack)
{
	t_stack	*copy;
	int	head;

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

void	print_stack(t_stack *stack)
{
	int	head;

	head = stack->head;
	printf("---\n");
	while (stack->head > -1)
		printf("%d\n", stack_pop(stack));
	printf("---\n");
	stack->head = head;
}

void	print_game(t_game *game)
{
	int	head_a;
	int	head_b;
	t_stack	*stack;

	stack = game->stack_a;
	printf("- -\n");
	head_a = game->stack_a->head;
	head_b = game->stack_b->head;
	if (stack->head > game->stack_b->head)
	{
		while (stack->head > -1)
		{
			printf("%d", stack_peek(stack));
			if (game->stack_b->head >= stack->head)
			{
				printf(" %d", stack_peek(game->stack_b));
				game->stack_b->head--;
			}
			stack->head--;
			printf("\n");
		}
	}
	else
	{
		while (game->stack_b->head > -1)
		{
			if (stack->head >= game->stack_b->head)
			{
				printf("%d", stack_peek(stack));
				stack->head--;
			}
			else
				printf(" ");
			printf(" %d", stack_peek(game->stack_b));
			game->stack_b->head--;
			printf("\n");
		}
	}
	printf("- -\n");
	stack->head = head_a;
	game->stack_b->head = head_b;
}

int	stack_get(t_stack *stack, int head)
{
	int	head_prev;
	int	ret;

	head_prev = stack->head;
	stack->head = head;
	ret = stack_peek(stack);
	stack->head = head_prev;
	return (ret);
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
