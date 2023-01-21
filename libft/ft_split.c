/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:40:13 by cjudie            #+#    #+#             */
/*   Updated: 2021/11/11 14:38:20 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_slov(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	slova_count(char const *s, char c)
{
	int	i;
	int	slova;

	slova = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			slova++;
		i++;
	}
	return (slova);
}

static void	*make_free(char **res, int slova)
{
	int	i;

	i = 0;
	while (i < slova)
	{	
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**razdel(char const *s, int slova, char c, char **res)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	while (i < slova)
	{
		while (*s == c)
			s++;
		len = len_slov(s, c);
		res[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!(res[i]))
			return (make_free(res, i));
		k = 0;
		while (k < len)
		{
			res[i][k] = *s;
			k++;
			s++;
		}
		res[i][k] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		slova;

	if (!s)
		return (NULL);
	slova = slova_count(s, c);
	res = (char **)malloc(sizeof(char *) * (slova + 1));
	if (!res)
		return (NULL);
	res = razdel(s, slova, c, res);
	return (res);
}
