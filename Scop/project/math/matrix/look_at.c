/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:52:43 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:52:44 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix			matrix_look_at(t_vector3 from, t_vector3 to, t_vector3 up)
{
	t_matrix		matrix;
	const t_vector3	a = vector3_normalize(vector3_sub(to, from));
	const t_vector3	b = vector3_normalize(vector3_cross(a, up));
	const t_vector3	c = vector3_cross(b, a);

	matrix = matrix_identity();
	matrix.data[0][0] = b.x;
	matrix.data[0][1] = c.x;
	matrix.data[0][2] = -a.x;
	matrix.data[1][0] = b.y;
	matrix.data[1][1] = c.y;
	matrix.data[1][2] = -a.y;
	matrix.data[2][0] = b.z;
	matrix.data[2][1] = c.z;
	matrix.data[2][2] = -a.z;
	matrix.data[3][0] = -vector3_dot(b, from);
	matrix.data[3][1] = -vector3_dot(c, from);
	matrix.data[3][2] = vector3_dot(a, from);
	return (matrix);
}
