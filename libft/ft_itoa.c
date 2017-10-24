/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:48:11 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/28 14:27:46 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size(int n)
{
	int				i;
	unsigned int	m;

	if (n <= 0)
	{
		i = 1;
		m = (unsigned int)-n;
	}
	else
	{
		i = 0;
		m = n;
	}
	while (m > 0)
	{
		m = m / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*s;
	int				i;
	unsigned int	m;

	i = find_size(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		m = (unsigned int)-n;
	}
	else
		m = n;
	s[i] = '\0';
	if (m == 0)
		s[0] = '0';
	while (m != '\0')
	{
		i--;
		s[i] = m % 10 + '0';
		m = m / 10;
	}
	return (s);
}
