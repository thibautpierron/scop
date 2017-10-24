/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:41:35 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/28 13:27:19 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int m;

	if (n < 0)
	{
		write(1, "-", 1);
		m = (unsigned int)-n;
	}
	else
		m = (unsigned int)n;
	if (m > 9)
	{
		ft_putnbr(m / 10);
		ft_putnbr(m % 10);
	}
	else
		ft_putchar(48 + m);
}
