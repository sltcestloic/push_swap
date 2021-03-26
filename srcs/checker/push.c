/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:43:01 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/26 16:45:34 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ps_push(t_stack *origin, t_stack *destination, char *msg)
{
	int	val;

	printf("%s\n", msg);
	val = stack_pop(origin);
	stack_push(destination, val);
}
