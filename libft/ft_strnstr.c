/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:56:05 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/26 11:59:00 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (!s2 || s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		if (s2[j] == s1[i])
		{
			while (s1[i + j] == s2[j] && s2[j] != '\0' && i + j < n)
				j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
