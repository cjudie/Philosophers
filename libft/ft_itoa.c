/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:49:02 by ctorrek           #+#    #+#             */
/*   Updated: 2021/11/11 16:17:38 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	l;
	int		i;

	l = n;
	i = len(l);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i--] = '\0';
	if (l == 0)
		res[0] = '0';
	if (l < 0)
	{
		res[0] = '-';
		l = -l;
	}
	while (l > 0)
	{
		res[i] = '0' + (l % 10);
		l = l / 10;
		i--;
	}
	return (res);
}
