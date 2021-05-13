/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:36:41 by lbertran          #+#    #+#             */
/*   Updated: 2021/05/13 13:55:22 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_error(char *message)
{
	ft_putstr_fd(HRED, 2);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(RESET, 2);
}

void	exit_error(char *message)
{
	print_error(message);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
