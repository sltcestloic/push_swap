/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:40:13 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/16 16:57:34 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_stack *stack = new_stack(5);

	stack_push(stack, 1);
	stack_push(stack, 28);
	stack_push(stack, 245);

	printf("Top element: %d\n", stack_peek(stack));
	printf("Size: %d\n", stack_size(stack));

	stack_pop(stack);
	stack_pop(stack);
	stack_pop(stack);

	printf("Empty stack ? %d\n", is_empty(stack));
}
