/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:30:35 by tpierron          #+#    #+#             */
/*   Updated: 2015/11/28 13:28:37 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int m;

	if (n < 0)
	{
		write(fd, "-", 1);
		m = (unsigned int)-n;
	}
	else
		m = (unsigned int)n;
	if (m > 9)
	{
		ft_putnbr_fd(m / 10, fd);
		ft_putnbr_fd(m % 10, fd);
	}
	else
		ft_putchar_fd(48 + m, fd);
}
