/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:33:38 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/26 15:32:14 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*src2;

	if (!dst || !src)
		return (NULL);
	src2 = src;
	tmp = malloc(len * sizeof(*src));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, src2, len);
	ft_memcpy(dst, tmp, len);
	return (dst);
}
