/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:50:03 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:50:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void			helper_counter(t_engine *engine)
{
	t_matrix		rotate;

	if (!engine->block_rotation &&
		++engine->counter_rotation >= SCOP_MODEL_ROTATION_FREQUENCY)
	{
		engine->counter_rotation = 0;
		engine->render_request = true;
		rotate = matrix_rotate_around_axis(
			SCOP_AXIS_Y, SCOP_MODEL_ROTATION_SPEED);
		model_update(engine, &rotate);
	}
	if (!engine->block_transition &&
		++engine->counter_transition >= SCOP_MOD_TRANSITION_FREQUENCY)
	{
		if (engine->model.mod_transition >= 1.f)
		{
			engine->block_transition = true;
			return ;
		}
		engine->counter_transition = 0;
		engine->render_request = true;
		engine->model.mod_transition += SCOP_MOD_TRANSITION_SPEED;
	}
}

void				loop(t_engine *engine)
{
	while (!glfwWindowShouldClose(engine->window))
	{
		glfwPollEvents();
		helper_counter(engine);
		if (engine->render_request)
			render(engine);
	}
}
