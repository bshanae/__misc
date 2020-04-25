/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:06:16 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 14:49:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3			vector3_mul(const t_vector3 *v1, double k)
{
	t_vector3		result;

	result.x = v1->x * k;
	result.y = v1->y * k;
	result.z = v1->z * k;
	return (result);
}

t_vector3			vector3_s_mul(t_vector3 v1, double k)
{
	v1.x *= k;
	v1.y *= k;
	v1.z *= k;
	return (v1);
}

void				vector3_rotate_x(t_vector3 *me, double theta)
{
	t_vector3		copy;

	copy = *me;
	me->y = copy.y * cosf(theta) + copy.z * sinf(theta);
	me->z = -1 * copy.y * sinf(theta) + copy.z * cosf(theta);
}

void				vector3_rotate_y(t_vector3 *me, double theta)
{
	t_vector3		copy;

	copy = *me;
	me->x = copy.x * cosf(theta) + copy.z * sinf(theta);
	me->z = -1 * copy.x * sinf(theta) + copy.z * cosf(theta);
}
