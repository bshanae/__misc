/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_x_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:50:25 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:50:26 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void				model_start(t_engine *engine)
{
	engine->model.meshes = vector_create(sizeof(t_mesh));
	engine->model.position = vector3_empty();
	engine->model.scale = 1.f;
	engine->model.rotation = matrix_identity();
	engine->model.transformation = matrix_identity();
	engine->model.mod_from = SCOP_MOD_RGB;
	engine->model.mod_to = SCOP_MOD_RGB;
	engine->model.mod_transition = 1.f;
	model_update(engine, NULL);
}

void				model_finish(t_engine *engine)
{
	t_vector_iter	iter;

	iter = vector_iter_set(engine->model.meshes, -1);
	while (vector_iter_next(&iter))
		mesh_destroy(vector_iter_ptr(&iter));
	vector_destroy(&engine->model.meshes);
}

void				model_load(t_engine *engine)
{
	int				i;

	i = 0;
	while (i < (int)engine->model.meshes->length)
		mesh_load(vector_at(engine->model.meshes, i++));
}

void				model_update(t_engine *engine, t_matrix *rotation)
{
	t_matrix		translate;
	t_matrix		scale;

	translate = matrix_translate(engine->model.position);
	scale = matrix_scale(engine->model.scale);
	engine->model.rotation = matrix_product(
		rotation ? *rotation : matrix_identity(), engine->model.rotation);
	engine->model.transformation = matrix_product_multiple(
		3, translate, engine->model.rotation, scale);
}

void				model_analyze(t_engine *engine)
{
	t_model			*model;
	int				i_vertex;
	int				i_mesh;
	t_mesh			*mesh;
	t_vector3		*vertex;

	model = &engine->model;
	model->min = vector3_pack(FLT_MAX, FLT_MAX, FLT_MAX);
	model->max = vector3_pack(FLT_MIN, FLT_MIN, FLT_MIN);
	i_mesh = 0;
	while (i_mesh < (int)model->meshes->length)
	{
		mesh = vector_at(model->meshes, i_mesh++);
		i_vertex = 0;
		while (i_vertex < (int)mesh->vector_vertex->length)
		{
			vertex = vector_at(mesh->vector_vertex, i_vertex++);
			model->min = vector3_min(*vertex, model->min);
			model->max = vector3_max(*vertex, model->max);
		}
	}
	model->size = vector3_sub(model->max, model->min);
	model->center = vector3_add(model->min, vector3_div(model->size, 2));
}
