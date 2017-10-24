/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:09:56 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/28 17:45:55 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = ft_strlen(dst);
	x = i;
	j = 0;
	if (size - x - 1 > 0)
	{
		while (i < size - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	dst[i] = '\0';
	if (x >= size)
		return (ft_strlen(src) + size);
	return (x + ft_strlen(src));
}
