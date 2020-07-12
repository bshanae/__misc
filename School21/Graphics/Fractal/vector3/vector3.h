/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:04:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/29 14:49:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <stdarg.h>
# include <math.h>
# include <stdlib.h>

typedef struct		s_vector3
{
	double			x;
	double			y;
	double			z;
}					t_vector3;

double				vector3_length(const t_vector3 *me);

void				vector3_normalize(t_vector3 *me);

void				vector3_s_sub_eq(t_vector3 *v1, t_vector3 v2);

void				vector3_s_add_eq(t_vector3 *v1, t_vector3 v2);

t_vector3			vector3_s_mul(t_vector3 v1, double k);

t_vector3			vector3_mul(const t_vector3 *v1, double k);

void				vector3_rotate_x(t_vector3 *me, double theta);

void				vector3_rotate_y(t_vector3 *me, double theta);

#endif
