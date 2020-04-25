/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:01:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 14:49:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera			*camera_new(double direction_length)
{
	t_camera		*new;

	if (!(new = (t_camera *)malloc(sizeof(t_camera))))
		exit(21);
	new->position = (t_vector3){0., 0., 0.};
	*(double *)&new->direction_length = direction_length;
	new->direction = (t_vector3){0., 0., -direction_length};
	new->axis_x = (t_vector3){1., 0., 0.};
	new->axis_y = (t_vector3){0., 1., 0.};
	new->axis_z = (t_vector3){0., 0., 1.};
	new->vp_axis_x = (t_vector3){1., 0., 0.};
	new->vp_axis_y = (t_vector3){0., 1., 0.};
	new->angles = (t_vector3){0., 0., 0.};
	return (new);
}

void				camera_delete(t_camera **me)
{
	free(*me);
	*me = NULL;
}

void				camera_recalculate(t_camera *me)
{
	int				index;
	t_vector3		*iter;

	me->direction = (t_vector3){0., 0., -1 * me->direction_length};
	me->axis_x = (t_vector3){1., 0., 0.};
	me->axis_y = (t_vector3){0., 1., 0.};
	me->axis_z = (t_vector3){0., 0., 1.};
	me->vp_axis_x = (t_vector3){1., 0., 0.};
	me->vp_axis_y = (t_vector3){0., 1., 0.};
	index = 0;
	iter = &me->direction;
	while (index < 6)
	{
		vector3_rotate_x(iter + index, me->angles.x);
		vector3_rotate_y(iter + index, me->angles.y);
		index++;
	}
}
