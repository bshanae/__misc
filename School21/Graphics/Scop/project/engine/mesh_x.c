/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:50:17 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:50:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_mesh				mesh_create(void)
{
	t_mesh			mesh;

	mesh.vector_vertex = vector_create(sizeof(float) * 3);
	mesh.vector_texture = vector_create(sizeof(float) * 2);
	mesh.vector_normal = vector_create(sizeof(float) * 3);
	mesh.vector_rgb_color = vector_create(sizeof(float) * 3);
	mesh.vector_random_color = vector_create(sizeof(float) * 3);
	mesh.material = NULL;
	mesh.vao = vao_create();
	return (mesh);
}

void				mesh_destroy(t_mesh *mesh)
{
	vector_destroy(&mesh->vector_vertex);
	vector_destroy(&mesh->vector_rgb_color);
	vector_destroy(&mesh->vector_random_color);
	vector_destroy(&mesh->vector_texture);
	vector_destroy(&mesh->vector_normal);
	vao_destroy(&mesh->vao);
}

void				mesh_load(t_mesh *mesh)
{
	mesh->vao = vao_create();
	mesh->vertex_number = (int)mesh->vector_vertex->length;
	vao_bind(&mesh->vao);
	vao_attribute(&mesh->vao, mesh->vector_vertex, 3);
	vao_attribute(&mesh->vao, mesh->vector_texture, 2);
	vao_attribute(&mesh->vao, mesh->vector_normal, 3);
	vao_attribute(&mesh->vao, mesh->vector_rgb_color, 3);
	vao_attribute(&mesh->vao, mesh->vector_random_color, 3);
	vao_bind(NULL);
}

void				mesh_draw(const t_mesh *mesh)
{
	vao_bind(&mesh->vao);
	glDrawArrays(GL_TRIANGLES, 0, mesh->vertex_number);
	vao_bind(NULL);
}