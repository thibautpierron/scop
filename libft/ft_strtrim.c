/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:35:41 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/29 21:07:46 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty(void)
{
	char *str;

	str = (char *)malloc(1);
	str[0] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		start;

	start = 0;
	if (!s)
		return (NULL);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	i = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
		i--;
	i++;
	if (start - i == 0)
		return ((char *)s);
	if (start < i)
	{
		str = (char *)malloc((i - start + 1) * sizeof(char));
		if (str)
			str = ft_strsub(s, start, (size_t)(i - start));
	}
	else
		str = empty();
	return (str);
}
