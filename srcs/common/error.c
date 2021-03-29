/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:36:41 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/29 15:25:17 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_error(char *message)
{
	ft_putstr_fd(HRED, 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(RESET, 2);
}

void	exit_error(char *message)
{
	print_error(message);
	print_error("\n");
	exit(EXIT_FAILURE);
}
