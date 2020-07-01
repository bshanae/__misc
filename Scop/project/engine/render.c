/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:50:57 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:50:59 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void				render(t_engine *engine)
{
	t_vector_iter	iter;
	t_mesh			*mesh;

	glClearColor(SCOP_BACKGROUND);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	uniform_update_common(engine);
	glActiveTexture(GL_TEXTURE0);
	texture_bind(&engine->texture);
	iter = vector_iter_set(engine->model.meshes, -1);
	while (vector_iter_next(&iter))
	{
		mesh = vector_iter_ptr(&iter);
		uniform_update_material(engine, mesh->material);
		mesh_draw(mesh);
	}
	glfwSwapBuffers(engine->window);
	engine->render_request = false;
}
