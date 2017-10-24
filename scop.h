/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:25:46 by tpierron          #+#    #+#             */
/*   Updated: 2016/01/11 14:49:12 by tpierron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <mlx.h>
# include "minilibx/mlx_opengl.h"
# include <OpenGL/gl.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h> 
# include <sys/types.h>
# include <fcntl.h>	
# include "libft/libft.h"
# include "math3d.h"

typedef struct			s_shaList
{
	const char 			*shaderText;
	GLenum				shaderType;
	unsigned int 		shader;
	struct s_shaList	*next;	
}						t_shaList;

typedef struct 			s_model
{
	float				*vertexArray;
	unsigned int 		vertexCount;

	float 				*uvArray;

	unsigned int		*indexArray;
	unsigned int 		indexCount;

	float 				minX;
	float 				maxX;
	float 				minY;
	float 				maxY;
	float 				minZ;
	float 				maxZ;

	float 				*extendedVertexArray;
}						t_model;

typedef struct		s_env
{
	void			*mlx;
	void			*win;

	// t_shaList		*shaderList;
	unsigned int	program;

	unsigned int 	vertexArrayID;
	unsigned int 	colorBuffer;
	unsigned int 	vbo;
	unsigned int 	ibo;
	unsigned int 	textureID;
	unsigned int 	uvBuffer;
	
	int				projectionMatrixUniformLocation;
	int				modelMatrixUniformLocation;
	int				worldLocation;
	int 			textLocation;
	int				fracLocation;

	t_matrix 		projectionMatrix;

	int				transformation;
	int 			axis;
	float 			intensity;
	int 			fracFlag;
	float			frac;

	t_model 		*model;
	unsigned char 			*texture;
}					t_env;

void 			initialization(t_env *e);

unsigned int 	createProgram(t_shaList *shaderListBegin);
t_shaList   	*addShader(t_shaList *list, char *shaderFile);

void 			createBuffers(t_env *e);
t_model     	*getModelFromFile(char *file);
void        	countVertexAndIndex(t_model *model, char *file);
void 			setQuadToTriangle(unsigned int *array);
int 			countSharedVertex(t_model *m);
void			loadTexture(char *file, t_env *e);
float 			*safeMallocFloat(int len);
char 			*safeMallocChar(int len);
int     		safeOpen(char *file, char *str);
int 			getFloatFromLine(char *str, float *array);
int 			getIntFromLine(char *str, unsigned int *array);

#endif
