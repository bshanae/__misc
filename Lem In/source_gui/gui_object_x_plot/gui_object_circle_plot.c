/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_circle_plot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:15:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:17:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

static void						helper_pixel4_filled(
	t_gui_object_circle_data *data, int delta_x, int delta_y)
{
	t_gui_object_point_i		from;
	t_gui_object_point_i		to;
	t_gui_object_line_bundle	bundle_line;

	from = (t_gui_object_point_i){data->position.x - delta_x + 1,
		data->position.y - delta_y + 1};
	to = (t_gui_object_point_i){data->position.x + delta_x - 1,
		data->position.y + delta_y - 1};
	gui_object_line_bundle_build(&bundle_line, data->buffer, from, to,
		global_false, data->color, global_false);
	gui_object_line_plot(&bundle_line);
	from = (t_gui_object_point_i){data->position.x + delta_x - 1,
		data->position.y - delta_y + 1};
	to = (t_gui_object_point_i){data->position.x - delta_x + 1,
		data->position.y + delta_y - 1};
	gui_object_line_bundle_build(&bundle_line, data->buffer, from, to,
		global_false, data->color, global_false);
	gui_object_line_plot(&bundle_line);
}

static void						helper_pixel4(
	t_gui_object_circle_data *data, int delta_x, int delta_y, float alpha)
{
	t_gui_object_point_i_bundle	bundle_point;

	if (data->is_filled)
		helper_pixel4_filled(data, delta_x, delta_y);
	gui_object_point_i_bundle_build(&bundle_point, data->buffer,
		(t_gui_object_point_i)
		{data->position.x + delta_x, data->position.y + delta_y},
		data->color, alpha, global_true);
	gui_object_point_i_plot(&bundle_point);
	gui_object_point_i_bundle_build(&bundle_point, data->buffer,
		(t_gui_object_point_i)
		{data->position.x - delta_x, data->position.y + delta_y},
		data->color, alpha, global_true);
	gui_object_point_i_plot(&bundle_point);
	gui_object_point_i_bundle_build(&bundle_point, data->buffer,
		(t_gui_object_point_i)
		{data->position.x + delta_x, data->position.y - delta_y},
		data->color, alpha, global_true);
	gui_object_point_i_plot(&bundle_point);
	gui_object_point_i_bundle_build(&bundle_point, data->buffer,
		(t_gui_object_point_i)
		{data->position.x - delta_x, data->position.y - delta_y},
		data->color, alpha, global_true);
	gui_object_point_i_plot(&bundle_point);
}

static void						helper_cycle_a(t_gui_object_circle_data *data)
{
	t_gui_object_point_i		iter_i;
	t_gui_object_point_f		iter_f;
	float						error;

	iter_i.x = 0;
	while ((float)iter_i.x <= data->quarter)
	{
		iter_f.y = data->radius * sqrtf(1 - (float)iter_i.x *
			(float)iter_i.x / data->radius2);
		error = iter_f.y - floorf(iter_f.y);
		helper_pixel4(data, iter_i.x, (int)floorf(iter_f.y), error);
		if (data->is_filled)
			helper_pixel4(data, iter_i.x, (int)floorf(iter_f.y) - 1, 1.f);
		else
			helper_pixel4(data, iter_i.x,
				(int)floorf(iter_f.y) - 1, 1.f - error);
		iter_i.x++;
	}
}

static void						helper_cycle_b(t_gui_object_circle_data *data)
{
	t_gui_object_point_i		iter_i;
	t_gui_object_point_f		iter_f;
	float						error;

	iter_i.y = 0;
	while ((float)iter_i.y <= data->quarter)
	{
		iter_f.x = data->radius * sqrtf(1 - (float)iter_i.y *
			(float)iter_i.y / data->radius2);
		error = iter_f.x - floorf(iter_f.x);
		helper_pixel4(data, (int)floorf(iter_f.x), iter_i.y, error);
		if (data->is_filled)
			helper_pixel4(data, (int)floorf(iter_f.x) - 1, iter_i.y, 1.f);
		else
			helper_pixel4(data, (int)floorf(iter_f.x) - 1,
				iter_i.y, 1.f - error);
		iter_i.y++;
	}
}

void							gui_object_circle_plot(
	const t_gui_object_circle_bundle *bundle)
{
	t_gui_object_circle_data	data;

	data.buffer = bundle->buffer;
	data.position = bundle->position;
	data.radius = (float)bundle->radius;
	data.radius2 = (data.radius * data.radius);
	data.quarter = roundf(data.radius2 / sqrtf(data.radius2 + data.radius2));
	data.color = bundle->color;
	data.is_filled = bundle->is_filled;
	helper_cycle_a(&data);
	helper_cycle_b(&data);
}
