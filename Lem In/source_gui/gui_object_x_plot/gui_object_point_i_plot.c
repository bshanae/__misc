/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_point_i_plot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:23:56 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:23:56 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

t_gui_object_point_f		gui_object_point_i_to_f(t_gui_object_point_i point)
{
	return ((t_gui_object_point_f){(float)point.x, (float)point.y});
}

void						gui_object_point_i_plot(
	const t_gui_object_point_i_bundle *bundle)
{
	t_gui_color		*ptr;

	if (bundle->point.x < 0 || bundle->point.y < 0)
		return ;
	if (bundle->point.x >= bundle->buffer->width)
		return ;
	if (bundle->point.y >= bundle->buffer->height)
		return ;
	ptr = bundle->buffer->data +
		bundle->point.y * bundle->buffer->width + bundle->point.x;
	if (bundle->blend)
		*ptr = gui_color_blend(*ptr, bundle->color, bundle->alpha);
	else
		*ptr = bundle->color;
}
