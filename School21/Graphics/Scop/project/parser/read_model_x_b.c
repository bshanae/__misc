/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_model_x_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:29:19 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 14:29:22 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_bool			helper_a(t_parser *parser)
{
	t_material			material;

	if (ft_str_prefix(parser->material.current_line, SCOP_MODEL_EMPTY))
		;
	else if (ft_str_prefix(parser->material.current_line, SCOP_MODEL_COMMENT))
		;
	else if (ft_str_prefix(parser->material.current_line, SCOP_MATERIAL_NEW))
	{
		material = material_create(
			parser->material.current_line + ft_strlen(SCOP_MATERIAL_NEW));
		vector_push(parser->material.library, &material);
		parser->material.current_material =
			vector_back(parser->material.library);
	}
	else if (ft_str_prefix(parser->material.current_line,
		SCOP_MATERIAL_TEXTURE))
		read_material_texture(parser);
	else
		return (false);
	return (true);
}

static t_bool			helper_b(t_parser *parser)
{
	if (ft_str_prefix(parser->material.current_line,
		SCOP_MATERIAL_AMBIENT))
		read_material_ambient(parser);
	else if (ft_str_prefix(parser->material.current_line,
		SCOP_MATERIAL_DIFFUSE))
		read_material_diffuse(parser);
	else if (ft_str_prefix(parser->material.current_line,
		SCOP_MATERIAL_SPECULAR))
		read_material_specular(parser);
	else if (ft_str_prefix(parser->material.current_line,
		SCOP_MATERIAL_EXPONENT))
		read_material_exponent(parser);
	else if (ft_str_prefix(parser->material.current_line,
		SCOP_MATERIAL_TRANSPARENT))
		read_material_transparent(parser);
	else if (ft_str_prefix(parser->material.current_line,
		SCOP_MATERIAL_DISSOLVE))
		read_material_dissolve(parser);
	else
		return (false);
	return (true);
}

void					read_model_library(t_parser *parser)
{
	char				*file;
	char				*path;
	int					fd;

	file = parser->model.current_line + ft_strlen(SCOP_MODEL_LIBRARY);
	if (!ft_str_suffix(file, ".mtl"))
		ft_raise_error(NULL, "Bad material library extension");
	path = ft_strjoin(parser->working_directory, file);
	fd = open(path, O_RDONLY);
	free(path);
	ft_assert_critical(
		parser->error_config, fd != -1, "Bad material library file");
	while (get_next_line(fd, &parser->material.current_line) > 0)
	{
		if (!helper_a(parser))
			helper_b(parser);
		free(parser->material.current_line);
		parser->material.current_line = NULL;
	}
	close(fd);
}

void					read_model_material(t_parser *parser)
{
	char				*name;
	t_vector_iter		iter;
	t_material			*material[2];
	t_interim_mesh		mesh;

	name = parser->model.current_line + ft_strlen(SCOP_MODEL_MATERIAL);
	material[0] = NULL;
	material[1] = NULL;
	while (is_space(name))
		name++;
	iter = vector_iter_set(parser->material.library, -1);
	while (!material[1] && vector_iter_next(&iter))
	{
		material[0] = vector_iter_ptr(&iter);
		if (!ft_strcmp(material[0]->name, name))
			material[1] = material[0];
	}
	if (!material[1])
		ft_raise_warning(parser->error_config, "Material not found");
	mesh = interim_mesh_create();
	mesh.material = material[1];
	vector_push(parser->model.data_mesh, &mesh);
	parser->model.current_mesh = vector_back(parser->model.data_mesh);
}
