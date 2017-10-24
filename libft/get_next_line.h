/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 09:44:33 by tpierron          #+#    #+#             */
/*   Updated: 2017/02/14 14:49:13 by thibautpier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 1

typedef struct		s_info
{
	int				fd;
	char			*info;
}                   t_info;

int		get_next_line(int const fd, char **line);

#endif
