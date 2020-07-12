/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:51:04 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:51:05 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

char				*read_file(const char *path)
{
	int				fd;
	char			*buffer_big;
	char			buffer_little[64];
	int				old_size;
	int				new_size;

	buffer_big = NULL;
	old_size = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_raise_warning(NULL, "Invalid file");
	while ((new_size = read(fd, buffer_little, 64)) > 0)
	{
		buffer_big = ft_realloc((void **)&buffer_big,
			old_size, old_size + new_size);
		ft_memcpy(buffer_big + old_size, buffer_little, new_size);
		old_size += new_size;
	}
	buffer_big = ft_realloc((void **)&buffer_big, old_size, old_size + 1);
	buffer_big[old_size] = '\0';
	return (buffer_big);
}

t_shader			shader_create(t_shader type, const char *path)
{
	t_shader		shader;
	char			*source;
	int				success;
	char			log[1024];

	shader = glCreateShader(type);
	source = read_file(path);
	glShaderSource(shader, 1, (const GLchar *const *)&source, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 1024, NULL, log);
		printf("Log : \n%s\n", log);
		ft_raise_error(NULL, "Can't create shader");
	}
	free(source);
	return (shader);
}

void				shader_destroy(t_shader *shader)
{
	glDeleteShader(*shader);
	*shader = -1;
}
