/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:19:49 by tpierron          #+#    #+#             */
/*   Updated: 2017/02/15 19:59:47 by thibautpier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		keyPress(int keycode, t_env *e)
{
	// ft_putnbr(keycode);
	(keycode == 123) ? e->intensity-- : 0; // gauche
	(keycode == 124) ? e->intensity++ : 0; // droite

	(keycode == 17) ? e->transformation = keycode : 0; // t
	(keycode == 1) ? e->transformation = keycode : 0; // s
	(keycode == 15) ? e->transformation = keycode : 0; // r

	(keycode == 7) ? e->axis = keycode : 0; // x
	(keycode == 16) ? e->axis = keycode : 0; // y
	(keycode == 6) ? e->axis = keycode : 0; // z

	if(keycode == 49) // space
	{
		e->intensity = 0;
		e->transformation = 0;
		e->axis = 0;
	}

	(keycode == 36) ? e->fracFlag *= -1 : 0;

	(keycode == 53) ? exit(0) : 0;

	return (0);
}

void 	transformMatrix(t_matrix *m, t_env *e)
{
	float scale;
	scale = 1 + e->intensity / 10;

	e->transformation == 17 && e->axis == 7 ? translateMatrix(m, e->intensity, 0.0f, 0.0f) : 0;
	e->transformation == 17 && e->axis == 16 ? translateMatrix(m, 0.0f, e->intensity, 0.0f) : 0;
	e->transformation == 17 && e->axis == 6 ? translateMatrix(m, 0.0f, 0.0f, e->intensity) : 0;

	e->transformation == 1 && e->axis == 0 ? scaleMatrix(m, scale, scale, scale) : 0;
	e->transformation == 1 && e->axis == 7 ? scaleMatrix(m, scale, 1.0f, 1.0f) : 0;
	e->transformation == 1 && e->axis == 16 ? scaleMatrix(m, 1.0f, scale, 1.0f) : 0;
	e->transformation == 1 && e->axis == 6 ? scaleMatrix(m, 1.0f, 1.0f, scale) : 0;

	e->transformation == 15 && e->axis == 7 ? rotateMatrixOnX(m, e->intensity / 2) : 0;
	e->transformation == 15 && e->axis == 16 ? rotateMatrixOnY(m, e->intensity / 2) : 0;
	e->transformation == 15 && e->axis == 6 ? rotateMatrixOnZ(m, e->intensity / 2) : 0;
}

int display(t_env *e) {
	static float offset = 0.0f;
	t_matrix model = {{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};
	offset += 1.0f;
	(offset > 359) ? offset = 0 : 0;
	translateMatrix(&model, -(e->model->maxX + e->model->minX) / 2,
							-(e->model->maxY + e->model->minY) / 2,
							-(e->model->maxZ + e->model->minZ) / 2);
	if (e->transformation == 0)
		rotateMatrixOnY(&model, degToRad(offset));
	else
		transformMatrix(&model, e);
	translateMatrix(&model, 0.0f, 0.0f, -5.0f);

	(e->frac > 1.0f) ? e->frac = 0.99f : 0;
	(e->frac < 0.0f) ? e->frac = 0.01f : 0;
	e->frac += 0.01 * e->fracFlag;

	// printf("%f\n", e->frac);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(e->program);

// ft_putstr("1\n");

	glUniformMatrix4fv(e->projectionMatrixUniformLocation, 1, GL_FALSE, &e->projectionMatrix.m[0]);
	// glUniformMatrix4fv(e->viewMatrixUniformLocation, 1, GL_FALSE, &worldMatrix.m[0]);
	glUniformMatrix4fv(e->modelMatrixUniformLocation, 1, GL_FALSE, &model.m[0]);
	glUniform1i(e->textLocation, 0);
	glUniform1f(e->fracLocation, e->frac);

// ft_putstr("2\n");

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, e->vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, e->ibo);

// ft_putstr("3\n");

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, e->colorBuffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

// ft_putstr("4\n");

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, e->uvBuffer);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, e->textureID);

// ft_putstr("5\n");

	// glPolygonMode(GL_FRONT, GL_LINE);
	glDrawElements(GL_TRIANGLES, e->model->indexCount, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

// ft_putstr("6\n");

	glUseProgram(0);

	mlx_opengl_swap_buffers(e->win);

	return 0;
}

void 	compileShaders(t_env *e)
{
	t_shaList *lst;
	lst = NULL;

	lst = addShader(lst, "shaders/vertex_final.glvs");
	lst = addShader(lst, "shaders/fragment_final.glfs");
	e->program = createProgram(lst);
	e->projectionMatrixUniformLocation = glGetUniformLocation(e->program, "projectionMatrix");
	e->modelMatrixUniformLocation = glGetUniformLocation(e->program, "modelMatrix");
	e->worldLocation = glGetUniformLocation(e->program, "world"); 
	e->textLocation = glGetUniformLocation(e->program, "textureSampler");
	e->fracLocation = glGetUniformLocation(e->program, "frac");
}

int		main(int ac, char **av)
{
	t_env	*e;
	if(!(e = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putstr("Malloc error\n");
		exit(0);
	}
	initialization(e);
	e->model = getModelFromFile(av[1]);
	loadTexture("ressources/texture.bmp", e);
	createBuffers(e);
	compileShaders(e);
	mlx_hook(e->win, 2, (1L << 0), &keyPress, e);
	mlx_loop_hook(e->mlx, display, e);
	mlx_loop(e->mlx);
	return (0);
}