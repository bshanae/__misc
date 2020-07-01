/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opengl_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:50:43 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:50:44 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void				opengl_start(t_engine *engine)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	engine->window = glfwCreateWindow(
		SCOP_WINDOW_WIDTH, SCOP_WINDOW_HEIGHT, SCOP_WINDOW_NAME, NULL, NULL);
	if (!engine->window)
		ft_raise_error(engine->error_config, "Failed to create GLFW window");
	glfwMakeContextCurrent(engine->window);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		ft_raise_error(engine->error_config, "Failed to initialize GLEW");
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwGetFramebufferSize(engine->window,
		&engine->window_width, &engine->window_height);
	glViewport(0, 0, engine->window_width, engine->window_height);
	glfwSetWindowUserPointer(engine->window, engine);
	glfwSetKeyCallback(engine->window, handle_key);
}

void				opengl_finish(void)
{
	glfwTerminate();
}
