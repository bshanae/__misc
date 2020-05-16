#include "engine.h"

t_bool				handle_common(t_engine *engine, int key)
{
	static t_bool	mod_line;

	if (key == GLFW_KEY_R)
		engine->block_rotation = !engine->block_rotation;
	else if (key == GLFW_KEY_P)
	{
		if (mod_line)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mod_line = !mod_line;
	}
	else
		return (false);
	return (true);
}

t_bool				handle_mod(t_engine *engine, int key)
{
	int 			new_mod;

	if (key == GLFW_KEY_1)
		new_mod = SCOP_MOD_RANDOM;
	else if (key == GLFW_KEY_2)
		new_mod = SCOP_MOD_RGB;
	else if (key == GLFW_KEY_3)
		new_mod = SCOP_MOD_MATERIAL;
	else if (key == GLFW_KEY_4)
		new_mod = SCOP_MOD_TEXTURE;
	else
		return (false);
	engine->model.mod_from = engine->model.mod_to;
	engine->model.mod_to = new_mod;
	engine->model.mod_transition = 0;
	engine->block_transition = false;
	return (true);
}

t_bool				handle_camera(t_engine *engine, int key)
{
	if (key == GLFW_KEY_A)
		camera_move(engine, axis_x, sign_minus, NULL);
	else if (key == GLFW_KEY_D)
		camera_move(engine, axis_x, sign_plus, NULL);
	else if (key == GLFW_KEY_W)
		camera_move(engine, axis_z, sign_minus, NULL);
	else if (key == GLFW_KEY_S)
		camera_move(engine, axis_z, sign_plus, NULL);
	else if (key == GLFW_KEY_Q)
		camera_move(engine, axis_y, sign_plus, NULL);
	else if (key == GLFW_KEY_E)
		camera_move(engine, axis_y, sign_minus, NULL);
	else if (key == GLFW_KEY_LEFT)
		camera_rotate(engine, axis_y, sign_plus, NULL);
	else if (key == GLFW_KEY_RIGHT)
		camera_rotate(engine, axis_y, sign_minus, NULL);
	else if (key == GLFW_KEY_UP)
		camera_rotate(engine, axis_x, sign_minus, NULL);
	else if (key == GLFW_KEY_DOWN)
		camera_rotate(engine, axis_x, sign_plus, NULL);
	else
		return (false);
	return (true);
}


t_bool				handle_model_a(t_engine *engine, int key)
{
	if (key == GLFW_KEY_A)
		camera_move(engine, axis_x, sign_minus, &engine->model.position);
	else if (key == GLFW_KEY_D)
		camera_move(engine, axis_x, sign_plus, &engine->model.position);
	else if (key == GLFW_KEY_W)
		camera_move(engine, axis_z, sign_minus, &engine->model.position);
	else if (key == GLFW_KEY_S)
		camera_move(engine, axis_z, sign_plus, &engine->model.position);
	else if (key == GLFW_KEY_Q)
		camera_move(engine, axis_y, sign_plus, &engine->model.position);
	else if (key == GLFW_KEY_E)
		camera_move(engine, axis_y, sign_minus, &engine->model.position);
	else if (key == GLFW_KEY_MINUS && engine->model.scale > SCOP_MODEL_SCALE_MIN)
		engine->model.scale -= SCOP_MODEL_SCALE_STEP;
	else if (key == GLFW_KEY_EQUAL && engine->model.scale < SCOP_MODEL_SCALE_MAX)
		engine->model.scale += SCOP_MODEL_SCALE_STEP;
	else
		return (false);
	model_update(engine, NULL);
	return (true);
}

t_bool				handle_model_b(t_engine *engine, int key)
{
	t_matrix 		rotation;

	rotation = matrix_identity();
	if (key == GLFW_KEY_J || key == GLFW_KEY_LEFT)
		camera_rotate(engine, axis_y, sign_plus, &rotation);
	else if (key == GLFW_KEY_L || key == GLFW_KEY_RIGHT)
		camera_rotate(engine, axis_y, sign_minus, &rotation);
	else if (key == GLFW_KEY_I || key == GLFW_KEY_UP)
		camera_rotate(engine, axis_x, sign_plus, &rotation);
	else if (key == GLFW_KEY_K || key == GLFW_KEY_DOWN)
		camera_rotate(engine, axis_x, sign_minus, &rotation);
	else if (key == GLFW_KEY_U)
		camera_rotate(engine, axis_z, sign_minus, &rotation);
	else if (key == GLFW_KEY_O)
		camera_rotate(engine, axis_z, sign_plus, &rotation);
	else
		return (false);
	engine->block_rotation = true;
	model_update(engine, &rotation);
	return (true);
}