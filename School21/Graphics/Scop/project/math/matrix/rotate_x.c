/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:53:15 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:53:16 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix			matrix_rotation_x(float angle)
{
	t_matrix		matrix;

	matrix = matrix_identity();
	matrix.data[1][1] = cosf(angle);
	matrix.data[1][2] = -sinf(angle);
	matrix.data[2][1] = sinf(angle);
	matrix.data[2][2] = cosf(angle);
	return (matrix);
}

t_matrix			matrix_rotation_y(float angle)
{
	t_matrix		matrix;

	matrix = matrix_identity();
	matrix.data[0][0] = cosf(angle);
	matrix.data[0][2] = sinf(angle);
	matrix.data[2][0] = -sinf(angle);
	matrix.data[2][2] = cosf(angle);
	return (matrix);
}

t_matrix			matrix_rotation_z(float angle)
{
	t_matrix		matrix;

	matrix = matrix_identity();
	matrix.data[0][0] = cosf(angle);
	matrix.data[0][1] = -sinf(angle);
	matrix.data[1][0] = sinf(angle);
	matrix.data[1][1] = cosf(angle);
	return (matrix);
}

t_matrix			matrix_rotation(t_vector3 angle)
{
	t_matrix		matrix;

	matrix = matrix_rotation_x(angle.x);
	matrix = matrix_product(matrix, matrix_rotation_y(angle.y));
	matrix = matrix_product(matrix, matrix_rotation_z(angle.z));
	return (matrix);
}

t_matrix			matrix_rotate_around_axis(t_vector3 axis, float angle)
{
	float			s;
	float			c;
	float			oc;
	t_matrix		matrix;

	axis = vector3_normalize(axis);
	matrix = matrix_identity();
	s = sinf(angle);
	c = cosf(angle);
	oc = 1.0f - c;
	matrix.data[0][0] = oc * axis.x * axis.x + c;
	matrix.data[0][1] = oc * axis.x * axis.y - axis.z * s;
	matrix.data[0][2] = oc * axis.z * axis.x + axis.y * s;
	matrix.data[1][0] = oc * axis.x * axis.y + axis.z * s;
	matrix.data[1][0] = oc * axis.x * axis.y + axis.z * s;
	matrix.data[1][1] = oc * axis.y * axis.y + c;
	matrix.data[1][2] = oc * axis.y * axis.z - axis.x * s;
	matrix.data[2][0] = oc * axis.z * axis.x - axis.y * s;
	matrix.data[2][1] = oc * axis.y * axis.z + axis.x * s;
	matrix.data[2][2] = oc * axis.z * axis.z + c;
	return (matrix);
}
