/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:57:08 by cjudie            #+#    #+#             */
/*   Updated: 2021/10/26 22:25:01 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = ft_strlen(s1);
	str = (char *)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	while (i >= 0)
	{
		str[i] = s1[i];
		i--;
	}
	return (str);
}
