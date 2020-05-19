#ifndef PARSER_H
# define PARSER_H

# include "scop_math.h"
# include "core.h"
# include "engine.h"
# include "libft_vector.h"
# include "libft_get_next_line.h"

typedef struct			s_interim_vertex
{
	int					vertex;
	int					texture;
	int					normal;
}						t_interim_vertex;

typedef struct			s_interim_mesh
{
	t_vector			*data;
	t_material			*material;
}						t_interim_mesh;

typedef struct			s_parser_model
{
	t_model				*target;
	t_vector			*data_vertex;
	t_vector			*data_texture;
	t_vector			*data_normal;
	t_vector			*data_mesh;
	char				*current_line;
	t_interim_mesh		*current_mesh;
	t_interim_vertex	*current_vertex;
}						t_parser_model;

typedef struct			s_parser_material
{
	t_material			white;
	t_vector			*library;
	char				*current_line;
	t_material			*current_material;
}						t_parser_material;

typedef struct			s_parser
{
	t_error_config		*error_config;
	t_engine			*engine;
	char				*working_directory;
	t_parser_model		model;
	t_parser_material	material;
}						t_parser;

void					parser_start(t_parser *parser, t_engine *engine);
void					parser_finish(t_parser *parser);

void					read_model(t_parser *parser, const char *path);
void					read_model_vertex(t_parser *parser);
void					read_model_texture(t_parser *parser);
void					read_model_normal(t_parser *parser);
void					read_model_face(t_parser *parser);
void					read_model_library(t_parser *parser);
void					read_model_material(t_parser *parser);

void					read_material_texture(t_parser *parser);
void					read_material_ambient(t_parser *parser);
void					read_material_diffuse(t_parser *parser);
void					read_material_specular(t_parser *parser);
void					read_material_exponent(t_parser *parser);
void					read_material_transparent(t_parser *parser);
void					read_material_dissolve(t_parser *parser);

void					generate_model(t_parser *parser);
t_mesh					generate_mesh(t_parser *parser);
void					generate_vertex(t_parser *parser, t_mesh *out);

void					fill_float(const char *in, int length, float *out);
t_interim_vertex		fill_interim_vertex(const char *in);

t_interim_mesh			interim_mesh_create();
void					interim_mesh_destroy(t_interim_mesh *mesh);

char					*extract_directory(const char *begin);

#endif
