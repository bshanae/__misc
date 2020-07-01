/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:56:46 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:56:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

static void			helper_rotate_x(t_vector3 *vector, float angle)
{
	t_vector3		copy;

	copy = *vector;
	vector->y = copy.y * cosf(angle) + copy.z * sinf(angle);
	vector->z = -1 * copy.y * sinf(angle) + copy.z * cosf(angle);
}

static void			helper_rotate_y(t_vector3 *vector, float angle)
{
	t_vector3		copy;

	copy = *vector;
	vector->x = copy.x * cosf(angle) + copy.z * sinf(angle);
	vector->z = -1 * copy.x * sinf(angle) + copy.z * cosf(angle);
}

static void			helper_rotate_z(t_vector3 *vector, float angle)
{
	t_vector3		copy;

	copy = *vector;
	vector->x = copy.x * cosf(angle) - copy.y * sinf(angle);
	vector->y = copy.x * sinf(angle) + copy.y * cosf(angle);
}

t_vector3			vector3_rotate(t_vector3 vector, t_axis axis, float angle)
{
	if (axis == axis_x)
		helper_rotate_x(&vector, angle);
	else if (axis == axis_y)
		helper_rotate_y(&vector, angle);
	else if (axis == axis_z)
		helper_rotate_z(&vector, angle);
	else
		ft_raise_warning(NULL, "Invalid axis");
	return (vector);
}

t_vector3			vector3_rotate_euler(t_vector3 vector, t_vector3 angle)
{
	vector = vector3_rotate(vector, axis_y, angle.y);
	vector = vector3_rotate(vector, axis_x, angle.x);
	vector = vector3_rotate(vector, axis_z, angle.z);
	return (vector);
}
