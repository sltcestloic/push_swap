/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:41:43 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/01 13:56:52 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

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

void	print_a_b(t_stack *stack_a, t_stack *stack_b)
{
	int	longest;

	longest = ft_intlen(stack_biggest(stack_a)) + 1;
	printf("%-*c -\n", longest, '-');
	while (stack_a->head > -1)
	{
		printf("%-*d", longest, stack_peek(stack_a));
		if (stack_b->head >= stack_a->head)
		{
			printf(" %d", stack_peek(stack_b));
			stack_b->head--;
		}
		stack_a->head--;
		printf("\n");
	}
	printf("%-*c -\n", longest, '-');
}

void	print_b_a(t_stack *stack_a, t_stack *stack_b)
{
	int	longest;

	longest = ft_intlen(stack_biggest(stack_a)) + 1;
	printf("%-*c -\n", longest, '-');
	while (stack_b->head > -1)
	{
		if (stack_a->head >= stack_b->head)
		{
			printf("%-*d", longest, stack_peek(stack_a));
			stack_a->head--;
		}
		else
			printf("%*s", longest, "");
		printf(" %d", stack_peek(stack_b));
		stack_b->head--;
		printf("\n");
	}
	printf("%-*c -\n", longest, '-');
}

void	print_game(t_game *game)
{
	int		head_a;
	int		head_b;
	t_stack	*stack;

	stack = game->stack_a;
	head_a = game->stack_a->head;
	head_b = game->stack_b->head;
	if (stack->head > game->stack_b->head)
		print_a_b(game->stack_a, game->stack_b);
	else
		print_b_a(game->stack_a, game->stack_b);
	stack->head = head_a;
	game->stack_b->head = head_b;
}
