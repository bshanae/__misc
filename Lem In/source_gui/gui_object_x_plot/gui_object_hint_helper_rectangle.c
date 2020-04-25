/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_hint_helper_rectangle.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:19:22 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:19:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

static void							helper_a(t_gui_object_hint_data *data)
{
	t_gui_object_rectangle_bundle	bundle;
	t_gui_object_point_i			temp;

	temp = data->circle_1;
	temp.y += GUI_OBJECT_HINT_CORNER_RADIUS - 1;
	gui_object_rectangle_bundle_build(&bundle, data->buffer, global_false,
		data->circle_4, temp, GUI_OBJECT_HINT_COLOR_FILL, global_true);
	gui_object_rectangle_plot(&bundle);
	temp = data->circle_1;
	temp.x += GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_rectangle_bundle_build(&bundle, data->buffer, global_false,
		data->circle_2, temp, GUI_OBJECT_HINT_COLOR_FILL, global_true);
	gui_object_rectangle_plot(&bundle);
}

static void							helper_b(t_gui_object_hint_data *data)
{
	t_gui_object_rectangle_bundle	bundle;
	t_gui_object_point_i			temp;

	temp = data->circle_3;
	temp.y -= GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_rectangle_bundle_build(&bundle, data->buffer, global_false,
		temp, data->circle_2, GUI_OBJECT_HINT_COLOR_FILL, global_true);
	gui_object_rectangle_plot(&bundle);
	temp = data->circle_3;
	temp.x -= GUI_OBJECT_HINT_CORNER_RADIUS;
	gui_object_rectangle_bundle_build(&bundle, data->buffer, global_false,
		temp, data->circle_4, GUI_OBJECT_HINT_COLOR_FILL, global_true);
	gui_object_rectangle_plot(&bundle);
}

void								gui_object_hint_helper_rectangle(
	t_gui_object_hint_data *data)
{
	t_gui_object_rectangle_bundle	bundle;

	gui_object_rectangle_bundle_build(&bundle, data->buffer, global_false,
		data->circle_3, data->circle_1,
		GUI_OBJECT_HINT_COLOR_FILL, global_true);
	gui_object_rectangle_plot(&bundle);
	helper_a(data);
	helper_b(data);
}
