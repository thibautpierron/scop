/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:14:12 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/26 14:37:20 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char *z1;
	const char *z2;

	z1 = s1;
	z2 = s2;
	if (n == 0)
		return (0);
	while (*z1 == *z2 && n != 1)
	{
		z1++;
		z2++;
		n--;
	}
	return ((unsigned char)*z1 - (unsigned char)*z2);
}
