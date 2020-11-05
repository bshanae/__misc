/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_point_f_plot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:23:24 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:23:24 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

t_gui_object_point_i		gui_object_point_f_to_i(t_gui_object_point_f point)
{
	return ((t_gui_object_point_i){(int)point.x, (int)point.y});
}

void						gui_object_point_f_plot(
	const t_gui_object_point_f_bundle *bundle)
{
	t_gui_color				*ptr;

	if (bundle->point.x < 0 || bundle->point.y < 0)
		return ;
	if (bundle->point.x >= (float)bundle->buffer->width)
		return ;
	if (bundle->point.y >= (float)bundle->buffer->height)
		return ;
	ptr = bundle->buffer->data +
		(int)bundle->point.y * bundle->buffer->width + (int)bundle->point.x;
	if (bundle->blend)
		*ptr = gui_color_blend(*ptr, bundle->color, bundle->alpha);
	else
		*ptr = bundle->color;
}
