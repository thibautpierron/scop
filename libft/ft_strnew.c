/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:36:01 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/28 12:21:17 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *mem;

	mem = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!mem)
		return (NULL);
	return (mem);
}
