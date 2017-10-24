/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadModel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:24:20 by thibautpier       #+#    #+#             */
/*   Updated: 2017/02/15 19:50:28 by thibautpier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void fillArrays(t_model *model, char *file)
{
    int             fd;
    int             i;
    int             j;
    int             l;
    char            *line;

    fd = safeOpen(file, "Can not open .obj file\n");
    i = 0;
    j = 0;
    int k;
    while (get_next_line(fd, &line) != 0)
    {
        k = 2;
        if(line[0] == 'v')
            i += getFloatFromLine(line, &model->vertexArray[i]);
        if(line[0] == 'f')
        {
            l = getIntFromLine(line, &model->indexArray[j]);
            j += l;
            if(l == 4)
            {
                setQuadToTriangle(&model->indexArray[j - 4]);
                j += 2;
            }
        }
        free(line);
    }
    free(line);
    close(fd);
    return;
}

static void        fillMinMax(t_model *model)
{
    int i;

    model->minX = 0;
    model->maxX = 0;
    model->minY = 0;
    model->maxY = 0;
    model->minZ = 0;
    model->maxZ = 0;    
    i = 0;
    while(i < model->vertexCount * 3)
    {
        model->vertexArray[i] < model->minX ? model->minX = model->vertexArray[i] : 0;
        model->vertexArray[i] > model->maxX ? model->maxX = model->vertexArray[i] : 0;

        model->vertexArray[i + 1] < model->minY ? model->minY = model->vertexArray[i + 1] : 0;
        model->vertexArray[i + 1] > model->maxY ? model->maxY = model->vertexArray[i + 1] : 0;

        model->vertexArray[i + 2] < model->minZ ? model->minZ = model->vertexArray[i + 2] : 0;
        model->vertexArray[i + 2] > model->maxZ ? model->maxZ = model->vertexArray[i + 2] : 0;
        i += 3;
    }
}

static void        fillUV(t_model *model)
{
    float rangeX = fabsf(model->maxX) + fabsf(model->minX);
    float rangeY = fabsf(model->maxY) + fabsf(model->minY);
    float rangeZ = fabsf(model->maxZ) + fabsf(model->minZ);

    int i = 0;
    int j = 0;
    if (rangeX > rangeZ)
    {
        while(j < (model->vertexCount * 3))
        {
            model->uvArray[i] = (model->extendedVertexArray[j] + fabsf(model->minX)) / rangeX;
            model->uvArray[i + 1] = (model->extendedVertexArray[j + 1] + fabsf(model->minY)) / rangeY;
            i += 2;
            j += 3;
        }
    }
    else
    {
        while(j < (model->vertexCount * 3))
        {
            model->uvArray[i] = (model->extendedVertexArray[j + 2] + fabsf(model->minZ)) / rangeZ;
            model->uvArray[i + 1] = (model->extendedVertexArray[j + 1] + fabsf(model->minY)) / rangeY;
            i += 2;
            j += 3;
        }
    }
}

static void createExtendedVertexArray(int n, t_model *m)
{
    int i = 0;
    int j;
    int max = (m->vertexCount - 1) * 3;
    
    m->extendedVertexArray = safeMallocFloat((m->vertexCount + n) * 3);
    while(i <= max + 3)
    {
        m->extendedVertexArray[i] = m->vertexArray[i];
        i++;
    }
    i = 0;
    while(i < m->indexCount)
    {
        j = 0;
        while(j < m->indexCount)
        {
            if(j != i && m->indexArray[j] == m->indexArray[i])
            {
                max += 3;
                m->extendedVertexArray[max ] = m->vertexArray[m->indexArray[i] * 3];
                m->extendedVertexArray[max + 1] = m->vertexArray[(m->indexArray[i] * 3) + 1];
                m->extendedVertexArray[max + 2] = m->vertexArray[(m->indexArray[i] * 3) + 2];
                m->vertexCount++;
                m->indexArray[j] = m->vertexCount - 1;
            }
            j++;
        }
        i++;
    }
}

t_model     *getModelFromFile(char *file)
{
    t_model *model;

    model = (t_model *)malloc(sizeof(t_model));
    if(!model)
    {
        ft_putstr("malloc error\n");
        exit(0);
    }
    countVertexAndIndex(model, file);
    model->vertexArray = safeMallocFloat(model->vertexCount * 3);
    model->indexArray = (unsigned int *)malloc(sizeof(unsigned int) * 
                            model->indexCount);
    if(!model->indexArray)
    {
        ft_putstr("malloc error\n");
        exit(0);
    }
    fillArrays(model, file);
    fillMinMax(model);
    createExtendedVertexArray(countSharedVertex(model), model);
    model->uvArray = safeMallocFloat(model->vertexCount * 2);
    fillUV(model);
    return  model;
}
