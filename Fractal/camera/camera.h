/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:57:42 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 14:49:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "ray.h"

typedef struct		s_camera
{
	t_vector3		position;
	const double	direction_length;
	t_vector3		direction;
	t_vector3		axis_x;
	t_vector3		axis_y;
	t_vector3		axis_z;
	t_vector3		vp_axis_x;
	t_vector3		vp_axis_y;
	t_vector3		angles;
}					t_camera;

t_camera			*camera_new(double direction_length);

void				camera_delete(t_camera **me);

void				camera_recalculate(t_camera *me);

#endif
