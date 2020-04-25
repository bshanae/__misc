/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_rectangle_plot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:24:08 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:24:50 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

static void						helper_filled(
	const t_gui_object_rectangle_bundle *bundle)
{
	t_gui_object_point_i		iter_left;
	t_gui_object_point_i		iter_right;
	t_gui_object_line_bundle	line;

	iter_left = (t_gui_object_point_i){bundle->min.x, bundle->min.y};
	iter_right = (t_gui_object_point_i){bundle->max.x, bundle->min.y};
	while (iter_left.y <= bundle->max.y)
	{
		gui_object_line_bundle_build(&line, bundle->buffer, iter_left,
			iter_right, global_false, bundle->color, global_true);
		gui_object_line_plot(&line);
		iter_left.y++;
		iter_right.y++;
	}
}

static void						helper_empty(
	const t_gui_object_rectangle_bundle *bundle)
{
	t_gui_object_point_i		temp;
	t_gui_object_line_bundle	line;

	temp = (t_gui_object_point_i){bundle->min.x, bundle->max.y};
	gui_object_line_bundle_build(&line, bundle->buffer, bundle->min,
		temp, global_false, bundle->color, global_true);
	gui_object_line_plot(&line);
	gui_object_line_bundle_build(&line, bundle->buffer, bundle->max,
		temp, global_false, bundle->color, global_true);
	gui_object_line_plot(&line);
	temp = (t_gui_object_point_i){bundle->max.x, bundle->min.y};
	gui_object_line_bundle_build(&line, bundle->buffer, bundle->min,
		temp, global_false, bundle->color, global_true);
	gui_object_line_plot(&line);
	gui_object_line_bundle_build(&line, bundle->buffer, bundle->max,
		temp, global_false, bundle->color, global_true);
	gui_object_line_plot(&line);
}

void							gui_object_rectangle_plot(
	const t_gui_object_rectangle_bundle *bundle)
{
	if (bundle->max.x < bundle->min.x || bundle->max.y < bundle->min.y)
		return (global_raise_warning("GUI, Rectangle : Incorrect definition"));
	if (bundle->is_filled)
		helper_filled(bundle);
	else
		helper_empty(bundle);
}
