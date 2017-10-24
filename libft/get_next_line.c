/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:53:17 by cobrunet          #+#    #+#             */
/*   Updated: 2017/02/14 14:49:36 by thibautpier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_info			*get_info(int fd, t_list **alst)
{
	t_list	*tmplst;
	t_info	tmpinfo;

	tmplst = *alst;
	while (tmplst)
	{
		if (((t_info*)(tmplst->content))->fd == fd)
			return (tmplst->content);
		tmplst = tmplst->next;
	}
	tmpinfo.fd = fd;
	tmpinfo.info = ft_strnew(BUFF_SIZE);
	if (!tmpinfo.info || !(tmplst = ft_lstnew(&tmpinfo, sizeof(tmpinfo))))
	{
		free(tmpinfo.info);
		return (NULL);
	}
	ft_lstadd(alst, tmplst);
	return ((t_info*)tmplst->content);
}

int				read_info(t_info *info, char **line)
{
	int		res;
	char	*str;

	res = 0;
	if ((str = ft_strchr(info->info, '\n')))
	{
		*str = '\0';
		str++;
		res = 1;
	}
	*line = ft_strdup(info->info);
	if (!*line)
		return (-1);
	if (res)
		ft_strcpy(info->info, str);
	else
		ft_strclr(info->info);
	return (res);
}

int				read_buf(char *buf, char **line, t_info *info)
{
	int		res;
	char	*str;

	res = 0;
	if ((str = ft_strchr(buf, '\n')))
	{
		*str = '\0';
		str++;
		ft_strcpy(info->info, str);
		res = 1;
	}
	str = *line;
	*line = ft_strjoin(*line, buf);
	if (!*line)
		return (-1);
	free(str);
	return (res);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_info			*info;

	if (!line || BUFF_SIZE <= 0 || !(info = get_info(fd, &lst)))
		return (-1);
	if (!(ret = read_info(info, line)))
	{
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if (ret < 0)
				return (-1);
			buf[ret] = '\0';
			if ((ret = read_buf(buf, line, info)))
				return (ret);
		}
		if (**line)
			return (1);
		return (0);
	}
	return (ret);
}
