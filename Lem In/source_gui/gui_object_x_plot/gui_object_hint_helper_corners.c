/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_hint_helper_corners.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:18:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:18:41 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

static void							helper_a(
	t_gui_object_hint_data *data, t_gui_object_point_i *center)
{
	t_gui_object_circle_bundle		bundle;

	data->circle_1 = *center;
	data->circle_1.x += data->width / 2 - GUI_OBJECT_HINT_CORNER_RADIUS;
	data->circle_1.y += GUI_OBJECT_HINT_RECT_HEIGHT / 2 -
		GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_circle_bundle_build(&bundle, data->buffer, data->circle_1,
		GUI_OBJECT_HINT_CORNER_RADIUS,
		GUI_OBJECT_HINT_COLOR_FILL, global_true);
	gui_object_circle_plot(&bundle);
	gui_object_circle_bundle_build(&bundle, data->buffer, data->circle_1,
		GUI_OBJECT_HINT_CORNER_RADIUS,
		GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_circle_plot(&bundle);
}

static void							helper_b(
	t_gui_object_hint_data *data, t_gui_object_point_i *center)
{
	t_gui_object_circle_bundle		bundle;

	data->circle_2 = *center;
	data->circle_2.x += data->width / 2 - GUI_OBJECT_HINT_CORNER_RADIUS;
	data->circle_2.y -= GUI_OBJECT_HINT_RECT_HEIGHT / 2 -
		GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_circle_bundle_build(&bundle, data->buffer, data->circle_2,
		GUI_OBJECT_HINT_CORNER_RADIUS,
		GUI_OBJECT_HINT_COLOR_FILL, global_true);
	gui_object_circle_plot(&bundle);
	gui_object_circle_bundle_build(&bundle, data->buffer, data->circle_2,
		GUI_OBJECT_HINT_CORNER_RADIUS,
		GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_circle_plot(&bundle);
}

static void							helper_c(
	t_gui_object_hint_data *data, t_gui_object_point_i *center)
{
	t_gui_object_circle_bundle		bundle;

	data->circle_3 = *center;
	data->circle_3.x -= data->width / 2 - GUI_OBJECT_HINT_CORNER_RADIUS;
	data->circle_3.y -= GUI_OBJECT_HINT_RECT_HEIGHT / 2 -
		GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_circle_bundle_build(&bundle, data->buffer, data->circle_3,
		GUI_OBJECT_HINT_CORNER_RADIUS,
		GUI_OBJECT_HINT_COLOR_FILL, global_true);
	gui_object_circle_plot(&bundle);
	gui_object_circle_bundle_build(&bundle, data->buffer, data->circle_3,
		GUI_OBJECT_HINT_CORNER_RADIUS,
		GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_circle_plot(&bundle);
}

static void							helper_d(
	t_gui_object_hint_data *data, t_gui_object_point_i *center)
{
	t_gui_object_circle_bundle		bundle;

	data->circle_4 = *center;
	data->circle_4.x -= data->width / 2 - GUI_OBJECT_HINT_CORNER_RADIUS;
	data->circle_4.y += GUI_OBJECT_HINT_RECT_HEIGHT / 2 -
		GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_circle_bundle_build(&bundle, data->buffer, data->circle_4,
		GUI_OBJECT_HINT_CORNER_RADIUS,
		GUI_OBJECT_HINT_COLOR_FILL, global_true);
	gui_object_circle_plot(&bundle);
	gui_object_circle_bundle_build(&bundle, data->buffer, data->circle_4,
		GUI_OBJECT_HINT_CORNER_RADIUS,
		GUI_OBJECT_HINT_COLOR_BORDER, global_false);
	gui_object_circle_plot(&bundle);
}

void								gui_object_hint_helper_corners(
	t_gui_object_hint_data *data)
{
	t_gui_object_point_i			center;

	center = (t_gui_object_point_i){data->lower_point.x,
		data->lower_point.y - GUI_OBJECT_HINT_TRI_HEIGHT -
		GUI_OBJECT_HINT_RECT_HEIGHT / 2};
	helper_a(data, &center);
	helper_b(data, &center);
	helper_c(data, &center);
	helper_d(data, &center);
}
