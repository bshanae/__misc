/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:51:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:53:08 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

double					quaternion_magnitude(t_quaternion *qtr)
{
	return (sqrt(qtr->real * qtr->real +
				qtr->i * qtr->i +
				qtr->j * qtr->j +
				qtr->k * qtr->k));
}

void					quaternion_normalize(t_quaternion *qtr)
{
	double				mgn;

	mgn = quaternion_magnitude(qtr);
	qtr->i /= mgn;
	qtr->j /= mgn;
	qtr->k /= mgn;
}

t_quaternion			quaternion_inverse(t_quaternion *qtr)
{
	return ((t_quaternion) {.real = qtr->real,
							.i = -1 * qtr->i,
							.j = -1 * qtr->j,
							.k = -1 * qtr->k});
}

t_quaternion			quaternion_multiply
	(t_quaternion *qtr1, t_quaternion *qtr2)
{
	t_quaternion		qtr_new;

	qtr_new.real = qtr1->real * qtr2->real
					- qtr1->i * qtr2->i
					- qtr1->j * qtr2->j
					- qtr1->k * qtr2->k;
	qtr_new.i = qtr1->real * qtr2->i
				+ qtr1->i * qtr2->real
				+ qtr1->j * qtr2->k
				- qtr1->k * qtr2->j;
	qtr_new.j = qtr1->real * qtr2->j
				- qtr1->i * qtr2->k
				+ qtr1->j * qtr2->real
				+ qtr1->k * qtr2->i;
	qtr_new.k = qtr1->real * qtr2->k
				+ qtr1->i * qtr2->j
				- qtr1->j * qtr2->i
				+ qtr1->k * qtr2->real;
	return (qtr_new);
}

t_quaternion			quaternion_generate_rotation
	(int mod_axis, double theta)
{
	t_quaternion		qtr;

	qtr.real = cos(theta / 2);
	qtr.i = sin(theta / 2) * (mod_axis == MOD_AXIS_X);
	qtr.j = sin(theta / 2) * (mod_axis == MOD_AXIS_Y);
	qtr.k = sin(theta / 2) * (mod_axis == MOD_AXIS_Z);
	return (qtr);
}
