/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBuffers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:42:36 by thibautpier       #+#    #+#             */
/*   Updated: 2017/02/15 19:59:28 by thibautpier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void 	createVertexBuffer(t_env *e)
{	
	glGenBuffers(1, &e->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, e->vbo);
    glBufferData(GL_ARRAY_BUFFER, e->model->vertexCount * 3 * sizeof(float), e->model->extendedVertexArray, GL_STATIC_DRAW);
	return;
}

static void 	createColorBuffer(t_env *e)
{
    float *colors = safeMallocFloat(e->model->vertexCount * 3);
    int i = 0;
	float r = 0.0f;
	int offset;

    while(i < e->model->vertexCount * 3)
    {
		if (r > 1.0f)
			r = 0.0f;
        colors[i] = 0.2f + r;
		colors[i + 1] = 0;
		colors[i + 2] = 0;
        colors[i + 3] = 0;
		colors[i + 4] = 0.2f + r;
		colors[i + 5] = 0;
        colors[i + 6] = 0;
		colors[i + 7] = 0;
		colors[i + 8] = 0.2f + r;

        i += 9;
		r += 0.3f;
    }

	glGenBuffers(1, &e->colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, e->colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, e->model->vertexCount * 3 * sizeof(float), colors, GL_STATIC_DRAW);
}

static void 	createIndexBuffer(t_env *e)
{	
	glGenBuffers(1, &e->ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, e->ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, e->model->indexCount * sizeof(unsigned int), e->model->indexArray, GL_STATIC_DRAW);
}


void createTextureCoordBuffer(t_env *e)
{
	glGenBuffers(1, &e->uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, e->uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, e->model->vertexCount * 2 * sizeof(float), e->model->uvArray, GL_STATIC_DRAW);
}

void 	createBuffers(t_env *e)
{
	createVertexBuffer(e);
	createColorBuffer(e);
	createTextureCoordBuffer(e);
	createIndexBuffer(e);
}