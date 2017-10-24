/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadTexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:09:05 by thibautpier       #+#    #+#             */
/*   Updated: 2017/02/15 14:26:50 by thibautpier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void loadTexture(char *file, t_env *e)
{
    int     fd;
    char     header[54];
    int width, height, imgSize;

    fd = safeOpen(file, "Can not open texture file\n");
    read(fd, header, 54);
    width = *(int*)&header[0x12];
    height = *(int*)&header[0x16];
    imgSize = width * height * 3;
    
    e->texture = (unsigned char *)malloc(sizeof(unsigned char) * imgSize);
    if(!e->texture)
    {
        ft_putstr("malloc error\n");
        exit(0);
    }
    read(fd, e->texture, imgSize);
    close(fd);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, e->texture);
}