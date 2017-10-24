/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadModelFunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:47:09 by thibautpier       #+#    #+#             */
/*   Updated: 2017/02/15 19:54:56 by thibautpier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void        countVertexAndIndex(t_model *model, char *file)
{
    unsigned int    vertexCount;
    unsigned int    indexCount;
    int             fd;
    char            *line;
    int             i;
    int             k;

    fd = safeOpen(file, "Can not open .obj file\n");
    vertexCount = 0;
    indexCount = 0;
    while (get_next_line(fd, &line))
    {
        if(line[0] == 'v')
            vertexCount++;
        if(line[0] == 'f')
        {
            i = 0;
            k = 0;
            while(line[i] != '\0')
            {
                if(line[i] == ' ')
                {
                    indexCount++;
                    k++;
                }
                i++;
            }
            if(k == 4)
                indexCount+=2;
        }
        free(line);
    }
    free(line);
    close(fd);
    model->vertexCount = vertexCount;
    model->indexCount = indexCount;
    return;
}

void setQuadToTriangle(unsigned int *array)
{
    array[5] = array[3];
    array[3] = array[0];
    array[4] = array[2];
    return;
}

int countSharedVertex(t_model *m)
{
    int count;
    int i;
    int j;

    i = 0;
    count = 0;
    while(i < m->indexCount)
    {
        j = 0;
        while(j < m->indexCount)
        {
            if(m->indexArray[j] == m->indexArray[i])
                count++;
            j++;
        }
        i++;
    }
    return count;
}