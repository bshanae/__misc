#include "parser.h"

void					read_material_texture(t_parser *parser)
{
	char				*file;
	char				*path;

	file = parser->material.current_line + ft_strlen(SCOP_MATERIAL_TEXTURE);
	path = ft_strjoin(parser->working_directory, file);
	parser->material.current_material->texture = texture_create(path);
	free(path);
}

void					read_material_ambient(t_parser *parser)
{
	fill_float(parser->material.current_line + ft_strlen(SCOP_MATERIAL_AMBIENT),
		3, &parser->material.current_material->ambient.x);
}

void					read_material_diffuse(t_parser *parser)
{
	fill_float(parser->material.current_line + ft_strlen(SCOP_MATERIAL_DIFFUSE),
		3, &parser->material.current_material->diffuse.x);
}

void					read_material_specular(t_parser *parser)
{
	fill_float(
		parser->material.current_line + ft_strlen(SCOP_MATERIAL_SPECULAR),
		3, &parser->material.current_material->specular.x);
}

void					read_material_exponent(t_parser *parser)
{
	fill_float(
		parser->material.current_line + ft_strlen(SCOP_MATERIAL_EXPONENT),
		1, &parser->material.current_material->specular_exponent);
}
