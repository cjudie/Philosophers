/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjudie <cjudie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:50:25 by cjudie            #+#    #+#             */
/*   Updated: 2021/10/27 15:15:21 by cjudie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	j = 0;
	i = ft_strlen(dst);
	len_dst = ft_strlen(dst);
	if (dstsize > 0 && len_dst < (dstsize - 1))
	{
		while (src[j] && len_dst + j < (dstsize - 1))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = 0;
	}
	if (len_dst >= dstsize)
		len_dst = dstsize;
	return (len_dst + ft_strlen(src));
}
