/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:28:30 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 14:28:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void				generate_model(t_parser *parser)
{
	t_vector_iter	iter;
	t_mesh			mesh;

	printf("Generating model, number of vertices : ");
	printf("%15.d", 0);
	iter = vector_iter_set(parser->model.data_mesh, -1);
	while (vector_iter_next(&iter))
	{
		parser->model.current_mesh = vector_iter_ptr(&iter);
		mesh = generate_mesh(parser);
		vector_push(parser->model.target->meshes, &mesh);
	}
	model_analyze(parser->engine);
	model_center(parser->engine);
	model_rgb_color(parser->engine);
	model_random_color(parser->engine);
	model_auto_scale(parser->engine);
	if (!parser->model.data_normal->length)
		model_auto_normal(parser->engine);
	if (!parser->model.data_texture->length)
		model_auto_texture(parser->engine);
	model_load(parser->engine);
	printf("\n");
}

t_mesh				generate_mesh(t_parser *parser)
{
	static int		count;
	int				i;
	t_mesh			mesh;

	mesh = mesh_create();
	mesh.material = parser->model.current_mesh->material;
	if (!mesh.material)
		mesh.material = &parser->material.white;
	i = 0;
	while (i < (int)parser->model.current_mesh->data->length)
	{
		count++;
		parser->model.current_vertex =
			vector_at(parser->model.current_mesh->data, i++);
		generate_vertex(parser, &mesh);
	}
	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	fflush(stdout);
	printf("%-15.d", count);
	return (mesh);
}

void				generate_vertex(t_parser *parser, t_mesh *out)
{
	t_vector3		*vertex;
	t_vector2		*texture;
	t_vector3		*normal;

	vertex = vector_at(parser->model.data_vertex,
		parser->model.current_vertex->vertex);
	texture = vector_at(parser->model.data_texture,
		parser->model.current_vertex->texture);
	normal = vector_at(parser->model.data_normal,
		parser->model.current_vertex->normal);
	vector_push(out->vector_vertex, vertex);
	vector_push(out->vector_texture, texture);
	vector_push(out->vector_normal, normal);
}
