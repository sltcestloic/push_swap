/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:40:13 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/27 15:17:56 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;
	int	i;

	if (ac > 4)
		exit_error("les suites de plus de 3 nombres ne sont pas encore supportées");
	else if (ac == 1)
		exit_error("Please specify a list of numbers.");	
	stack = new_stack(ac - 1);
	i = 1;
	while (i < ac)
	{
		if (atoi(av[i]) == 0 && ft_strcmp("0", av[i]) != 0)
			exit_error("Invalid argument.");
		stack_push(stack, atoi(av[i]));
		i++;
	}
	print_stack(stack);
	//printf("pb\nsa\npb\npb\nsa\npb\nrb\npa\npa\npa\npa\n");
}
