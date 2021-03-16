/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:36:41 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/16 16:46:16 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_error(char *message)
{
	ft_putstr_fd(message, 1);
}

void	exit_error(char *message)
{
	print_error(message);
	exit(EXIT_FAILURE);
}
