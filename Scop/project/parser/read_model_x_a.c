#include "parser.h"

void					read_model_vertex(t_parser *parser)
{
	t_vector3			out;

	fill_float(parser->model.current_line, 3, &out.x);
	vector_push(parser->model.data_vertex, &out);
}

void					read_model_texture(t_parser *parser)
{
	t_vector2			out;

	fill_float(parser->model.current_line, 2, &out.x);
	vector_push(parser->model.data_texture, &out);
}

void					read_model_normal(t_parser *parser)
{
	t_vector3			out;

	fill_float(parser->model.current_line, 3, &out.x);
	vector_push(parser->model.data_normal, &out);
}

static void				helper_write(t_parser *parser, t_vector *vector)
{
	int 				i;

	i = 1;
	while (i < (int)vector->length - 1)
	{
		vector_push(parser->model.current_mesh->data, vector_at(vector, 0));
		vector_push(parser->model.current_mesh->data, vector_at(vector, i));
		vector_push(parser->model.current_mesh->data, vector_at(vector, ++i));
	}
}

void 					read_model_face(t_parser *parser)
{
	char				*local_line;
	t_interim_vertex	vertex;
	t_vector			*vector;

	local_line = parser->model.current_line;
	vector = vector_create(sizeof(t_interim_vertex));
	while (1)
	{
		if (!(local_line = ft_strchr(local_line, ' ')))
			break ;
		while (is_space(local_line))
			local_line++;
		if (!local_line[0])
			break ;
		vertex = fill_interim_vertex(local_line);
		vector_push(vector, &vertex);
	}
	helper_write(parser, vector);
	vector_destroy(&vector);
}