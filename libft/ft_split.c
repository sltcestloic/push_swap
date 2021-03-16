/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:21:23 by lbertran          #+#    #+#             */
/*   Updated: 2020/12/22 15:33:36 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_w_start(const char *str, char c, int index)
{
	int	i;

	i = index;
	while (str[i] != c)
	{
		if (i == 0)
		{
			i = -1;
			break ;
		}
		i--;
	}
	i += 1;
	return (i);
}

char	*ft_strrdup(const char *str, int start, int end)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	while (start <= end)
	{
		ret[i] = str[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}

void	free_all(char **ret, int size)
{
	size_t	i;

	i = 0;
	while (i < (size_t)size)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

int		count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	char	**ret;
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	if (!str)
		return (NULL);
	if (!(ret = malloc(sizeof(char*) * (count_words(str, c) + 1))))
		return (NULL);
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
		{
			if (!(ret[wc] = ft_strrdup(str, get_w_start(str, c, i), i)))
			{
				free_all(ret, wc);
				return (NULL);
			}
			wc++;
		}
		i++;
	}
	ret[wc] = 0;
	return (ret);
}
