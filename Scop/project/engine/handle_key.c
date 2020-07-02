/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:49:45 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:49:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void			helper(t_engine *engine, int key)
{
	static t_bool	mod_model;

	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(engine->window, GL_TRUE);
	else if (key == GLFW_KEY_R)
		engine->block_rotation = !engine->block_rotation;
	else if (key == GLFW_KEY_ENTER)
		mod_model = !mod_model;
	else if (handle_common(engine, key))
		;
	else if (handle_mod(engine, key))
		;
	else if (!mod_model && handle_camera(engine, key))
		;
	else if (mod_model && handle_model_a(engine, key))
		;
	else if (mod_model && handle_model_b(engine, key))
		;
	else
		return ;
	engine->render_request = true;
}

void				handle_key(
					GLFWwindow *window,
					int key,
					int scancode,
					int action,
					int mode)
{
	scancode = 0;
	mode = 0;
	if (action != GLFW_PRESS && action != GLFW_REPEAT)
		return ;
	helper(glfwGetWindowUserPointer(window), key);
}
