#include "engine.h"

static void			helper(t_engine *engine, int key)
{
	static t_bool	mod_model;

	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(engine->window, GL_TRUE);
	else if (key == GLFW_KEY_ENTER)
	{
		mod_model = !mod_model;
		engine->block_rotation_by_mod = mod_model;
		engine->block_rotation = false;
	}
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
	t_engine		*engine;

	scancode = 0;
	mode = 0;
	if (action != GLFW_PRESS && action != GLFW_REPEAT)
		return ;
	helper(glfwGetWindowUserPointer(window), key);
}
