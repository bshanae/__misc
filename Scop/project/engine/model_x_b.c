/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_x_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:50:30 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:50:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void				model_rgb_color(t_engine *engine)
{
	int				i_mesh;
	int				i_vertex;
	t_mesh			*mesh;
	t_vector3		*vertex;
	t_vector3		color;

	i_mesh = 0;
	while (i_mesh < (int)engine->model.meshes->length)
	{
		mesh = vector_at(engine->model.meshes, i_mesh++);
		i_vertex = 0;
		while (i_vertex < (int)mesh->vector_vertex->length)
		{
			vertex = vector_at(mesh->vector_vertex, i_vertex++);
			color.x = (vertex->x - engine->model.min.x) / engine->model.size.x;
			color.y = (vertex->y - engine->model.min.y) / engine->model.size.y;
			color.z = (vertex->z - engine->model.min.z) / engine->model.size.z;
			vector_push(mesh->vector_rgb_color, &color);
		}
	}
}

void				model_random_color(t_engine *engine)
{
	int				i_mesh;
	int				i_vertex;
	t_mesh			*mesh;
	t_vector3		vector;

	srand(time(NULL));
	i_mesh = 0;
	while (i_mesh < (int)engine->model.meshes->length)
	{
		mesh = vector_at(engine->model.meshes, i_mesh++);
		i_vertex = 0;
		while (i_vertex++ < (int)mesh->vector_vertex->length)
		{
			vector.x = (float)rand() / (float)(RAND_MAX);
			vector.y = (float)rand() / (float)(RAND_MAX);
			vector.z = (float)rand() / (float)(RAND_MAX);
			vector_push(mesh->vector_random_color, &vector);
		}
	}
}

void				model_center(t_engine *engine)
{
	t_model			*model;
	int				i_mesh;
	int				i_vertex;
	t_mesh			*mesh;
	t_vector3		*vertex;

	model = &engine->model;
	i_mesh = 0;
	while (i_mesh < (int)model->meshes->length)
	{
		mesh = vector_at(model->meshes, i_mesh++);
		i_vertex = 0;
		while (i_vertex < (int)mesh->vector_vertex->length)
		{
			vertex = vector_at(mesh->vector_vertex, i_vertex++);
			*vertex = vector3_sub(*vertex, model->center);
		}
	}
}
