/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_mxl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:49:33 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/28 15:49:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rm.h"

int					rm_key_press(int key, void *ptr)
{
	t_rm			*me;

	me = ptr;
	if (key == KEY_ESC)
		exit(1);
	else if (key == KEY_SHIFT)
		me->shift_hold = 1;
	else if (key == KEY_OPT)
		me->option_hold = 1;
	else if (rm_ctrl_easy(me, key))
		;
	else if (rm_ctrl_ikido(me, key))
		;
	else if (rm_ctrl_camera_position(me, key))
		;
	else if (rm_ctrl_camera_direction(me, key))
		;
	else if (rm_ctrl_object_iter(me, key))
		;
	else if (rm_ctrl_julia(me, key))
		;
	else
		return (0);
	rm_render(me);
	return (1);
}

int					rm_key_release(int key, void *ptr)
{
	t_rm			*me;

	me = (t_rm *)ptr;
	if (key == KEY_SHIFT)
		me->shift_hold = 0;
	else if (key == KEY_OPT)
		me->option_hold = 0;
	return (0);
}

int					rm_exit(void *ptr)
{
	t_rm			**me;

	me = (t_rm **)ptr;
	rm_delete(me);
	exit(0);
}
