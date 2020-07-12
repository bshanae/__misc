/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:52:50 by bshanae           #+#    #+#             */
/*   Updated: 2020/07/01 13:52:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop_math.h"

t_matrix			matrix_perspective(
					float fov,
					float aspect_ratio,
					float near,
					float far)
{
	t_matrix		matrix;
	const float		f = tanf(degrees_to_radians(fov) / 2.f);

	matrix.data[0][0] = 1.f / (aspect_ratio * f);
	matrix.data[0][1] = 0;
	matrix.data[0][2] = 0;
	matrix.data[0][3] = 0;
	matrix.data[1][0] = 0;
	matrix.data[1][1] = 1.f / f;
	matrix.data[1][2] = 0;
	matrix.data[1][3] = 0;
	matrix.data[2][0] = 0;
	matrix.data[2][1] = 0;
	matrix.data[2][2] = -1 * (far + near) / (far - near);
	matrix.data[2][3] = -1;
	matrix.data[3][0] = 0;
	matrix.data[3][1] = 0;
	matrix.data[3][2] = -2 * far * near / (far - near);
	matrix.data[3][3] = 0;
	return (matrix);
}
