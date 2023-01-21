/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:55:25 by cjudie            #+#    #+#             */
/*   Updated: 2021/10/27 19:33:57 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[len] && ft_strchr(set, s1[len]) && i < (len + 1))
		len--;
	str = (char *)malloc(sizeof(char) * (len - i + 2));
	if (!str)
		return (NULL);
	j = 0;
	while (i < (len + 1))
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
