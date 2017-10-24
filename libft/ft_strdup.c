/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:28:21 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/23 14:49:21 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*cpy;
	int		i;

	cpy = (char *)malloc(ft_strlen(s) * sizeof(*cpy));
	if (cpy)
	{
		i = 0;
		while (s[i] != '\0')
		{
			cpy[i] = s[i];
			i++;
		}
		cpy[i + 1] = '\0';
		return (cpy);
	}
	else
		return (NULL);
}
