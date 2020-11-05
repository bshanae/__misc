/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:51:19 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 20:50:06 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm.h"

int					rm_ctrl_camera_position(t_rm *me, int key)
{
	if (me->mod != MOD_3D)
		return (0);
	if (key == KEY_W)
		vector3_s_sub_eq(&me->camera->position,
			vector3_s_mul(me->camera->axis_z, CAMERA_POS_STEP));
	else if (key == KEY_S)
		vector3_s_add_eq(&me->camera->position,
			vector3_s_mul(me->camera->axis_z, CAMERA_POS_STEP));
	else if (key == KEY_A)
		vector3_s_sub_eq(&me->camera->position,
			vector3_s_mul(me->camera->axis_x, CAMERA_POS_STEP));
	else if (key == KEY_D)
		vector3_s_add_eq(&me->camera->position,
			vector3_s_mul(me->camera->axis_x, CAMERA_POS_STEP));
	else if (key == KEY_E)
		me->camera->position.y -= CAMERA_POS_STEP;
	else if (key == KEY_Q)
		me->camera->position.y += CAMERA_POS_STEP;
	else
		return (0);
	return (1);
}

int					rm_ctrl_camera_direction(t_rm *me, int key)
{
	if (me->mod != MOD_3D)
		return (0);
	if (me->option_hold || me->shift_hold)
		return (0);
	if (key == KEY_LEFT_1)
		me->camera->angles.y += CAMERA_DIR_STEP;
	else if (key == KEY_RIGHT_1)
		me->camera->angles.y -= CAMERA_DIR_STEP;
	else if (key == KEY_DOWN_1)
		me->camera->angles.x += CAMERA_DIR_STEP;
	else if (key == KEY_UP_1)
		me->camera->angles.x -= CAMERA_DIR_STEP;
	else
		return (0);
	camera_recalculate(me->camera);
	return (1);
}

int					rm_ctrl_julia(t_rm *me, int key)
{
	if (me->object->iter != SDF_I_JULIA)
		return (0);
	if (me->shift_hold && key == KEY_LEFT_1)
		me->object->julia.value.x -= JULIA_STEP;
	else if (me->shift_hold && key == KEY_RIGHT_1)
		me->object->julia.value.x += JULIA_STEP;
	else if (me->shift_hold && key == KEY_UP_1)
		me->object->julia.value.y += JULIA_STEP;
	else if (me->shift_hold && key == KEY_DOWN_1)
		me->object->julia.value.y -= JULIA_STEP;
	else if (me->option_hold && key == KEY_LEFT_1)
		me->object->julia.value.z -= JULIA_STEP;
	else if (me->option_hold && key == KEY_RIGHT_1)
		me->object->julia.value.z += JULIA_STEP;
	else if (me->option_hold && key == KEY_UP_1)
		me->object->julia.value.w += JULIA_STEP;
	else if (me->option_hold && key == KEY_DOWN_1)
		me->object->julia.value.w -= JULIA_STEP;
	else
		return (0);
	return (1);
}

int					rm_ctrl_object_iter(t_rm *me, int key)
{
	if (key == KEY_1 || key == KEY_2)
		me->object->iter = key == KEY_1 ? 0 : 1;
	else if (key == KEY_3 || key == KEY_4)
		me->object->iter = key == KEY_3 ? 2 : 3;
	else if (key == KEY_5 || key == KEY_6)
		me->object->iter = key == KEY_5 ? 4 : 5;
	else if (key == KEY_7)
		me->object->iter = 6;
	else if (key == KEY_8)
		me->easy->mod = 1;
	else if (key == KEY_9)
		me->easy->mod = 2;
	else if (key == KEY_0)
		;
	else
		return (0);
	if (key == KEY_0)
		me->mod = MOD_IKIDO;
	else if (key == KEY_8 || key == KEY_9)
		me->mod = MOD_EASY;
	else
		me->mod = MOD_3D;
	return (1);
}
