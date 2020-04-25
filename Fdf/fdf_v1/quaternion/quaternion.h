/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:05:52 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:51:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include "some_math.h"

typedef struct			s_quaternion
{
	double				real;
	double				i;
	double				j;
	double				k;
}						t_quaternion;

double					quaternion_magnitude(t_quaternion *qtr);

void					quaternion_normalize(t_quaternion *qtr);

t_quaternion			quaternion_inverse(t_quaternion *qtr);

t_quaternion			quaternion_multiply
	(t_quaternion *qtr1, t_quaternion *qtr2);

t_quaternion			quaternion_generate_rotation
	(int mod_axis, double theta);

# define MOD_AXIS_X		1
# define MOD_AXIS_Y		2
# define MOD_AXIS_Z		3

#endif
