/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vo_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:55:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 19:16:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vo.h"

static void				vo_control_iso(t_vo *vo, int key)
{
	if (key == KEY_MINUS_1 || key == KEY_MINUS_2)
		map_zoom(&vo->map, MOD_SIGN_MINUS);
	else if (key == KEY_PLUS_1 || key == KEY_PLUS_2)
		map_zoom(&vo->map, MOD_SIGN_PLUS);
	else if (key == KEY_A)
		map_shift(&vo->map, MOD_AXIS_X, MOD_SIGN_MINUS);
	else if (key == KEY_D)
		map_shift(&vo->map, MOD_AXIS_X, MOD_SIGN_PLUS);
	else if (key == KEY_W)
		map_shift(&vo->map, MOD_AXIS_Y, MOD_SIGN_MINUS);
	else if (key == KEY_S)
		map_shift(&vo->map, MOD_AXIS_Y, MOD_SIGN_PLUS);
	else
		return ;
	vo_render(vo);
}

static void				vo_control_free(t_vo *vo, int key)
{
	if (key == KEY_LEFT_1 || key == KEY_LEFT_2)
		map_rotate(&vo->map, MOD_AXIS_Y, MOD_SIGN_MINUS);
	else if (key == KEY_RIGHT_1 || key == KEY_RIGHT_2)
		map_rotate(&vo->map, MOD_AXIS_Y, MOD_SIGN_PLUS);
	else if (key == KEY_UP_1 || key == KEY_UP_2)
		map_rotate(&vo->map, MOD_AXIS_X, MOD_SIGN_PLUS);
	else if (key == KEY_DOWN_1 || key == KEY_DOWN_2)
		map_rotate(&vo->map, MOD_AXIS_X, MOD_SIGN_MINUS);
	else if (key == KEY_BRACE_L)
		map_rotate(&vo->map, MOD_AXIS_Z, MOD_SIGN_MINUS);
	else if (key == KEY_BRACE_R)
		map_rotate(&vo->map, MOD_AXIS_Z, MOD_SIGN_PLUS);
	else if (key == KEY_MINUS_1 || key == KEY_MINUS_2)
		map_zoom(&vo->map, MOD_SIGN_MINUS);
	else if (key == KEY_PLUS_1 || key == KEY_PLUS_2)
		map_zoom(&vo->map, MOD_SIGN_PLUS);
	else if (key == KEY_A || key == KEY_D)
		map_shift(&vo->map, MOD_AXIS_X,
			key == KEY_A ? MOD_SIGN_MINUS : MOD_SIGN_PLUS);
	else if (key == KEY_W || key == KEY_S)
		map_shift(&vo->map, MOD_AXIS_Y,
			key == KEY_W ? MOD_SIGN_MINUS : MOD_SIGN_PLUS);
	else
		return ;
	vo_render(vo);
}

int						vo_key_press(int key, void *ptr)
{
	t_vo				*vo;

	vo = (t_vo *)ptr;
	if (key == KEY_SHIFT)
		vo->shift_mod = 1;
	else if (vo->term_mod)
		vo_term_get(vo, key);
	else if (key == KEY_ESC)
		vo_close(vo);
	else if (vo->shift_mod && key == KEY_COLON)
		vo_term_launch(vo);
	else if (key == KEY_I)
		vo->map.mod = MAP_MOD_ISO;
	else if (key == KEY_F)
		vo->map.mod = MAP_MOD_FREE;
	else if (key == KEY_P)
		map_palette_set(&vo->map, 1);
	else if (vo->map.mod == MAP_MOD_ISO)
		vo_control_iso(vo, key);
	else if (vo->map.mod == MAP_MOD_FREE)
		vo_control_free(vo, key);
	if (!vo->term_mod && (key == KEY_I || key == KEY_F || key == KEY_P))
		vo_render(vo);
	return (0);
}

int						vo_key_release(int key, void *ptr)
{
	t_vo				*vo;

	vo = (t_vo *)ptr;
	if (key == KEY_SHIFT)
		vo->shift_mod = 0;
	return (0);
}
