#include "engine.h"

void				camera_start(t_engine *engine)
{
	t_camera		*camera;

	camera = &engine->camera;
	camera->matrix_projection = matrix_perspective(
		SCOP_CAMERA_FOV,
		(float)engine->window_width / (float)engine->window_height,
		SCOP_CAMERA_NEAR, SCOP_CAMERA_FAR);
	camera->matrix_view = matrix_empty();
	camera->position = SCOP_CAMERA_POSITION;
	camera->direction = SCOP_CAMERA_DIRECTION;
	camera->axis_x = vector3_pack(1, 0, 0);
	camera->axis_y = vector3_pack(0, 1, 0);
	camera->axis_z = vector3_pack(0, 0, 1);
	camera->angles = vector3_empty();
	camera_update(engine);
}

void				camera_move(
					t_engine *engine,
					t_axis axis,
					t_sign sign,
					t_vector3 *target)
{
	t_camera		*camera;
	t_vector3		work_vector;
	float			delta;

	camera = &engine->camera;
	delta = (float)sign *
		(target ? SCOP_TARGET_MOVEMENT_SPEED : SCOP_CAMERA_MOVEMENT_SPEED);
	work_vector = vector3_empty();
	if (!target)
		target = &camera->position;
	if (axis == axis_x)
		work_vector = camera->axis_x;
	else if (axis == axis_y)
		work_vector = camera->axis_y;
	else if (axis == axis_z)
		work_vector = camera->axis_z;
	work_vector = vector3_mul(work_vector, delta);
	*target = vector3_add(*target, work_vector);
	camera_update(engine);
}

void				camera_rotate(
					t_engine *engine,
					t_axis axis,
					t_sign sign,
					t_matrix *target)
{
	t_camera		*camera;
	float			delta;

	camera = &engine->camera;
	delta = (float)sign *
		(target ? SCOP_TARGET_ROTATION_SPEED : SCOP_CAMERA_ROTATION_SPEED);
	if (!target)
	{
		if (axis == axis_x)
			camera->angles.x += delta;
		else if (axis == axis_y)
			camera->angles.y += delta;
		camera_update(engine);
	}
	else
	{
		if (axis == axis_x)
			*target = matrix_rotate_around_axis(camera->axis_x, delta);
		else if (axis == axis_y)
			*target = matrix_rotate_around_axis(camera->axis_y, delta);
		else if (axis == axis_z)
			*target = matrix_rotate_around_axis(camera->axis_z, delta);
	}
}

void				camera_update(t_engine *engine)
{
	t_camera		*camera;

	camera = &engine->camera;
	camera->angles.x = clamp(
		M_PI * -0.5f + SCOP_EPSILON, M_PI * 0.5f - SCOP_EPSILON,
		camera->angles.x);
	camera->direction = SCOP_CAMERA_DIRECTION;
	camera->direction = vector3_rotate_euler(camera->direction, camera->angles);
	camera->axis_x = vector3_rotate_euler(SCOP_AXIS_X, camera->angles);
	camera->axis_y = vector3_rotate_euler(SCOP_AXIS_Y, camera->angles);
	camera->axis_z = vector3_rotate_euler(SCOP_AXIS_Z, camera->angles);
	camera->matrix_view = matrix_look_at(camera->position,
		vector3_add(camera->position, camera->direction),
		vector3_pack(0, 1, 0));
}
