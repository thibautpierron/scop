/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibautpierron <thibautpierron@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:17:08 by thibautpier       #+#    #+#             */
/*   Updated: 2017/02/15 19:28:28 by thibautpier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

unsigned int createShader(GLenum shaderType, const char *shaderStr)
{
    unsigned int shader;
    int status;
    GLint infoLogLength;
    char *strInfoLog;

    shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderStr, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);    
        strInfoLog = safeMallocChar(infoLogLength + 1);
        glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);
        ft_putstr("shader compilation error:\n");
        if (shaderType == GL_VERTEX_SHADER)
            ft_putstr("Compile failure in vertex shader");
        if (shaderType == GL_FRAGMENT_SHADER)
            ft_putstr("Compile failure in fragment shader");
        ft_putstr(strInfoLog);
    }
    return shader;
}

unsigned int createProgram(t_shaList *shaderListBegin)
{
    unsigned int program;
    t_shaList *shader;
    int status;
    GLint infoLogLength;
    char *strInfoLog;

    shader = shaderListBegin;
    program = glCreateProgram();
    while (shader)
    {
        shader->shader = createShader(shader->shaderType, shader->shaderText);
        glAttachShader(program, shader->shader);
        shader = shader->next;
    }

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        ft_putstr("linker failure:\n");
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);    
        strInfoLog = safeMallocChar(infoLogLength + 1);
        glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
        ft_putstr(strInfoLog);
    }

    shader = shaderListBegin;
    while (shader)
    {
        glDetachShader(program, shader->shader);
        glDeleteShader(shader->shader);
        free((void*)shader->shaderText);
        shader = shader->next;
    }
    return program; 
}