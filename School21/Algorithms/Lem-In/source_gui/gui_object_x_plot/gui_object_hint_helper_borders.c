/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_hint_helper_borders.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:18:11 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:18:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

static void						helper_a(t_gui_object_hint_data *data)
{
	t_gui_object_point_i		a;
	t_gui_object_point_i		b;
	t_gui_object_line_bundle	line;

	a = data->circle_1;
	b = data->circle_2;
	a.x += GUI_OBJECT_HINT_CORNER_RADIUS;
	b.x += GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_line_bundle_build(&line, data->buffer, a, b,
		global_false, GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_line_plot(&line);
	a = data->circle_2;
	b = data->circle_3;
	a.y -= GUI_OBJECT_HINT_CORNER_RADIUS;
	b.y -= GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_line_bundle_build(&line, data->buffer, a, b,
		global_false, GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_line_plot(&line);
	a = data->circle_3;
	b = data->circle_4;
	a.x -= GUI_OBJECT_HINT_CORNER_RADIUS;
	b.x -= GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_line_bundle_build(&line, data->buffer, a, b,
		global_false, GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_line_plot(&line);
}

static void						helper_b(t_gui_object_hint_data *data)
{
	t_gui_object_point_i		a;
	t_gui_object_point_i		b;
	t_gui_object_line_bundle	line;

	a = (t_gui_object_point_i){data->lower_point.x - GUI_OBJECT_HINT_TRI_WIDTH
		/ 2, data->lower_point.y - GUI_OBJECT_HINT_TRI_HEIGHT};
	gui_object_line_bundle_build(&line, data->buffer, data->lower_point, a,
		global_false, GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_line_plot(&line);
	b = data->circle_4;
	b.y += GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_line_bundle_build(&line, data->buffer, a, b, global_false,
		GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_line_plot(&line);
	a = (t_gui_object_point_i){
		data->lower_point.x + GUI_OBJECT_HINT_TRI_WIDTH / 2,
		data->lower_point.y - GUI_OBJECT_HINT_TRI_HEIGHT};
	gui_object_line_bundle_build(&line, data->buffer, data->lower_point,
		a, global_false, GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_line_plot(&line);
	b = data->circle_1;
	b.y += GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_line_bundle_build(&line, data->buffer, a, b,
		global_false, GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_line_plot(&line);
}

void							gui_object_hint_helper_borders(
	t_gui_object_hint_data *data)
{
	helper_a(data);
	helper_b(data);
}
