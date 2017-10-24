/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:13:32 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/30 13:17:45 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	const char		*src2;
	unsigned char	*dst2;

	i = 0;
	src2 = src;
	dst2 = dst;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == c)
			return (dst2 + i + 1);
		i++;
	}
	return (NULL);
}
