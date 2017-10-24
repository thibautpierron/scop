/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genericTools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 10:53:26 by thibautpier       #+#    #+#             */
/*   Updated: 2017/02/15 19:42:35 by thibautpier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int     safeOpen(char *file, char *str)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        ft_putstr(str);
        exit(0);
    }
    return fd;
}

float *safeMallocFloat(int len)
{
    float *ret;

    ret = (float*)malloc(sizeof(float) * len);
    if(!ret)
    {
        ft_putstr("malloc error\n");
        exit(0);
    }
    return ret;
}

char *safeMallocChar(int len)
{
    char *ret;

    ret = (char*)malloc(sizeof(char) * len);
    if(!ret)
    {
        ft_putstr("malloc error\n");
        exit(0);
    }
    return ret;
}

int getIntFromLine(char *str, unsigned int *array)
{
    int i;
    int j;
    
    i = 2;
    j = 0;
    while(str[i])
    {
        if(str[i - 1] == ' ')
        {
            array[j] = atoi(&str[i]) - 1; ///change atoi
            j++;
        }
        i++;
    }
    return j;
}

int getFloatFromLine(char *str, float *array)
{
    int i;
    int j;
    
    i = 2;
    j = 0;
    while(str[i])
    {
        if(str[i - 1] == ' ')
        {
            array[j] = atof(&str[i]); ///change atof
            j++;
        }
        i++;
    }
    return j;
}