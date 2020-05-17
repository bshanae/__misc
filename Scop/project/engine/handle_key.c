#include "engine.h"

void 				handle_key(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	static t_bool	mod_model;
	t_engine		*engine;

	if (action != GLFW_PRESS && action != GLFW_REPEAT)
		return ;
	engine = glfwGetWindowUserPointer(window);
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