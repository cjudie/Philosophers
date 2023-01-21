/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:32:49 by cjudie            #+#    #+#             */
/*   Updated: 2022/03/31 22:55:59 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	space_checker(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\n'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	dup_checker(t_index *index)
{
	int		i;
	int		j;

	i = 0;
	while (i < index->size)
	{
		j = i + 1;
		while (j < index->size)
		{
			if (index->pointer[i] == index->pointer[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sort_checker(t_index *index)
{
	int	i;

	i = 0;
	while (i + 1 < index->size)
	{
		if (index->pointer[i] > index->pointer[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	int_checker(const char *str)
{
	size_t			i;
	size_t			j;
	int				num;

	i = 0;
	j = 0;
	num = 0;
	while (space_checker(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		j++;
		if ((num * 10 + (str[i] - '0')) / 10 != num)
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (!str[i] && j);
}

int	put_error(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}
