/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:42:33 by thibautpier       #+#    #+#             */
/*   Updated: 2017/02/15 19:37:40 by thibautpier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		initMlx(t_env *e)
{
    e->mlx = mlx_init();
	e->win = mlx_new_opengl_window(e->mlx, 500, 500, "Scop");
	mlx_opengl_window_set_context(e->win);
    return;
}

static void		initGL(t_env *e)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glEnable(GL_TEXTURE_2D);
	glGenVertexArrays(1, &e->vertexArrayID);
	glBindVertexArray(e->vertexArrayID);
	glGenTextures(1, &e->textureID);
	glBindTexture(GL_TEXTURE_2D, e->textureID);
    return;
}

void			initialization(t_env *e)
{
    initMlx(e);
    initGL(e);
	e->projectionMatrix = createProjectionMatrix(60.0f, 1.0f, 1.0f, 100.0f);
	e->transformation = 0;
	e->axis = 0;
	e->intensity = 0.0f;
	e->fracFlag = 1;
	e->frac = 1.0f;
    return;
}