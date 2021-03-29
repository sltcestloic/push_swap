/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:01:14 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/29 13:34:04 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** Condition 1: 2 1 3
** Condition 2: 3 1 2
** Condition 3: 2 3 1
** Condition 4: 1 3 2
** Else: 3 2 1
*/
void	sort_3(t_stack *stack)
{
	int	top;
	int	mid;
	int	bottom;

	top = stack_get(stack, 2);
	mid = stack_get(stack, 1);
	bottom = stack_get(stack, 0);
	if (top > mid && mid < bottom && top < bottom)
		ps_swap(stack, "sa");
	else if (top > mid && mid < bottom && top > bottom)
		ps_rotate(stack, "ra");
	else if (top < mid && mid > bottom && top > bottom)
		ps_rrotate(stack, "rra");
	else if (top < mid && mid > bottom && top < bottom)
	{
		ps_swap(stack, "sa");
		ps_rotate(stack, "ra");
	}
	else
	{
		ps_swap(stack, "sa");
		ps_rrotate(stack, "rra");
	}
}
