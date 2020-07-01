/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:28:44 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 14:28:45 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void				parser_start(t_parser *parser, t_engine *engine)
{
	t_interim_mesh	mesh;

	parser->error_config = engine->error_config;
	parser->engine = engine;
	parser->working_directory = NULL;
	parser->model.target = &engine->model;
	parser->model.data_vertex = vector_create(sizeof(float) * 3);
	parser->model.data_texture = vector_create(sizeof(float) * 2);
	parser->model.data_normal = vector_create(sizeof(float) * 3);
	parser->model.data_mesh = vector_create(sizeof(t_interim_mesh));
	mesh = interim_mesh_create();
	vector_push(parser->model.data_mesh, &mesh);
	parser->model.current_mesh = vector_back(parser->model.data_mesh);
	parser->model.current_line = NULL;
	parser->material.white = material_create("");
	parser->material.white.ambient = vector3_pack(0.6f, 0.6f, 0.6f);
	parser->material.white.diffuse = vector3_pack(0.4f, 0.4f, 0.4f);
	parser->material.library = vector_create(sizeof(t_material));
	parser->material.current_line = NULL;
	parser->material.current_material = NULL;
}

void				parser_finish(t_parser *parser)
{
	int				i;

	free(parser->working_directory);
	vector_destroy(&parser->model.data_vertex);
	vector_destroy(&parser->model.data_normal);
	vector_destroy(&parser->model.data_texture);
	i = 0;
	while (i < (int)parser->model.data_mesh->length)
		interim_mesh_destroy(vector_at(parser->model.data_mesh, i++));
	vector_destroy(&parser->model.data_mesh);
	i = 0;
	while (i < (int)parser->material.library->length)
		material_destroy(vector_at(parser->material.library, i++));
	vector_destroy(&parser->material.library);
}
