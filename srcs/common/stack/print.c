/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:41:43 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/02 12:59:26 by lbertran         ###   ########lyon.fr   */
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

void	print_a_b(t_game *game)
{
	int	longest;
	int	val;

	longest = ft_intlen(stack_biggest(game->stack_a)) + 1;
	printf("%-*c -\n", longest, '-');
	while (game->stack_a->head > -1)
	{
		val = stack_peek(game->stack_a);
		printf("%s%-*d%s", get_color(val, game), longest, val, RESET);
		if (game->stack_b->head >= game->stack_a->head)
		{
			val = stack_peek(game->stack_b);
			printf(" %s%d%s", get_color(val, game), val, RESET);
			game->stack_b->head--;
		}
		game->stack_a->head--;
		printf("\n");
	}
	printf("%-*c -\n", longest, '-');
}

void	print_b_a(t_game *game)
{
	int	longest;
	int	val;

	longest = ft_intlen(stack_biggest(game->stack_a)) + 1;
	printf("%-*c -\n", longest, '-');
	while (game->stack_b->head > -1)
	{
		if (game->stack_a->head >= game->stack_b->head)
		{
			val = stack_peek(game->stack_a);
			printf("%s%-*d%s", get_color(val, game), longest, val, RESET);
			game->stack_a->head--;
		}
		else
			printf("%*s", longest, "");
		val = stack_peek(game->stack_b);
		printf(" %s%d%s", get_color(val, game), val, RESET);
		game->stack_b->head--;
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
		print_a_b(game);
	else
		print_b_a(game);
	stack->head = head_a;
	game->stack_b->head = head_b;
}
