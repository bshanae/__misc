/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:48:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:50:22 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point_3d				point_init(double x, double y, double z)
{
	t_point_3d			new;

	new.qtr.real = 0;
	new.qtr.i = x;
	new.qtr.j = y;
	new.qtr.k = z;
	new.color.mix = WHITE;
	if (z < 0)
		new.color_type = COLOR_T_MINUS;
	else if (!z)
		new.color_type = COLOR_T_ZERO;
	else
		new.color_type = COLOR_T_PLUS;
	return (new);
}

static t_color			point_color_build
	(const t_color *start, const t_color *end,
	const double *percent, const double *rate)
{
	t_color				new;

	new.rgb.r = (unsigned char)(((1 - *percent) *
		start->rgb.r + *percent * end->rgb.r) * *rate);
	new.rgb.g = (unsigned char)(((1 - *percent) *
		start->rgb.g + *percent * end->rgb.g) * *rate);
	new.rgb.b = (unsigned char)(((1 - *percent) *
		start->rgb.b + *percent * end->rgb.b) * *rate);
	return (new);
}

t_color					point_color_gradient
	(const t_point_2d *start, const t_point_2d *end,
	const int *current_x, double rate)
{
	double				percent;

	if (start->color.mix == end->color.mix)
		return (color_adjust(start->color.mix, rate));
	percent = (end->x - start->x) ?
		((double)(*current_x - start->x) / (double)(end->x - start->x)) :
		(1.0);
	return (point_color_build(&start->color, &end->color, &percent, &rate));
}
