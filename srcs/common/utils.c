/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:36:29 by lbertran          #+#    #+#             */
/*   Updated: 2021/04/01 14:13:31 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	splitlen(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
