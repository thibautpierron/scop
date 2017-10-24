/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:21:54 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/29 20:45:47 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (res);
		res++;
		while (s[i] != c)
		{
			if (s[i] == '\0')
				return (res);
			i++;
		}
		i++;
	}
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		plt;

	if (!s)
		return (NULL);
	tab = (char**)malloc((count_words(s, c) + 1) * sizeof(char*));
	if (!tab)
		return (NULL);
	tab[count_words(s, c)] = (char *)'\0';
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		plt = i;
		while (s[i] != c)
			i++;
		tab[j] = ft_strsub(s, plt, i - plt);
		j++;
	}
	return (tab);
}
