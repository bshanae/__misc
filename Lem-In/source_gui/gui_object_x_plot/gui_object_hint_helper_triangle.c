/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_hint_helper_triangle.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:19:53 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:19:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

void								gui_object_hint_helper_triangle(
	t_gui_object_hint_data *data)
{
	int								x_delta;
	t_gui_object_point_i			triangle_mid;
	t_gui_object_point_i			iter;
	t_gui_object_line_bundle		line;

	triangle_mid = (t_gui_object_point_i){data->lower_point.x,
		data->lower_point.y - GUI_OBJECT_HINT_TRI_HEIGHT};
	x_delta = -GUI_OBJECT_HINT_TRI_WIDTH / 2 + 1;
	while (x_delta <= GUI_OBJECT_HINT_TRI_WIDTH / 2 - 1)
	{
		iter = triangle_mid;
		iter.x += x_delta;
		gui_object_line_bundle_build(&line, data->buffer, data->lower_point,
			iter, global_false, GUI_OBJECT_HINT_COLOR_FILL, global_true);
		gui_object_line_plot(&line);
		x_delta++;
	}
}
