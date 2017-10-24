/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:12:00 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/25 10:49:16 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	if (!s2 || s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		if (s2[j] == s1[i])
		{
			while (s1[i + j] == s2[j] && s2[j] != '\0')
				j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
