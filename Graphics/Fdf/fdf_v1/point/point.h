/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:48:26 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:49:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "color.h"
# include "quaternion.h"

typedef struct			s_point_2d
{
	int					x;
	int					y;
	t_color				color;
}						t_point_2d;

typedef struct			s_point_3d
{
	t_quaternion		qtr;
	t_color				color;
	int					color_type;
	void				*ptr;
}						t_point_3d;

# define COLOR_T_MINUS	0
# define COLOR_T_ZERO	1
# define COLOR_T_PLUS	2

t_point_3d				point_init(double x, double y, double z);

t_color					point_color_gradient
	(const t_point_2d *start, const t_point_2d *end,
	const int *current_x, double rate);

#endif
