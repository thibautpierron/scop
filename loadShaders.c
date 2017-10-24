#include "scop.h"

static GLenum      getShaderType(char *fileName)
{
    int     i;

    i = 1;
    while (fileName[i] != '.')
        i++;
    if ((ft_strcmp(&fileName[i], ".glvs")) == 0)
        return GL_VERTEX_SHADER;
    else if ((ft_strcmp(&fileName[i], ".glfs")) == 0)
        return GL_FRAGMENT_SHADER;
    ft_putstr("Can not open shader file\n");
	exit(1);
}

static int         getFileLen(char *file)
{
    int     fileLen;
    int     fd;
    char     *line;

    fd = safeOpen(file, "Can not open shader file\n");
    fileLen = 0;
    while (get_next_line(fd, &line) != 0)
    {
        fileLen += ft_strlen(line) + 1;
        free(line);
    }
    free(line);
    close(fd);
    return fileLen;
}

static const char  *getShader(char *shaderFile)
{
    int         fd;
    char        *line;
    int         fileLen;
    char  *shader;
    
    fileLen = getFileLen(shaderFile);
    shader = safeMallocChar(fileLen);
    fd = safeOpen(shaderFile, "Can not open shader file\n");
    while (get_next_line(fd, &line) != 0)
    {
        shader = ft_strcat(shader, line);
        shader = ft_strcat(shader, "\n\0");
        free(line);
    }
    free(line);
    close(fd);
    return shader;
}

t_shaList   *addShader(t_shaList *list, char *shaderFile)
{
    t_shaList *new;

    if (!(new = (t_shaList *)malloc(sizeof(t_shaList))))
    {
        ft_putstr("malloc error\n");
        exit(0);
    }
    new->shaderType = getShaderType(shaderFile);
    new->shaderText = getShader(shaderFile);
    new->next = list;
    return new;
}