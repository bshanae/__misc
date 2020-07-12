/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_line_aa_plot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:20:30 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:20:34 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

static void						helper_set_l(
	t_gui_object_line_aa_data *data,
	t_gui_object_point_f *l,
	t_gui_object_point_f *l1,
	t_gui_object_point_f *l2)
{
	if (data->is_steep)
	{
		*l1 = (t_gui_object_point_f){l->y, l->x};
		*l2 = (t_gui_object_point_f){l->y + 1.f, l->x};
	}
	else
	{
		*l1 = (t_gui_object_point_f){l->x, l->y};
		*l2 = (t_gui_object_point_f){l->x, l->y + 1.f};
	}
}

static float					helper_endpoint(
	t_gui_object_line_aa_data *data,
	t_gui_object_point_f *point,
	t_gui_object_point_f *l)
{
	t_gui_object_point_f		end;
	float						gap;
	t_gui_object_point_f		l1;
	t_gui_object_point_f		l2;
	t_gui_object_point_f_bundle	bundle;

	end.x = gui_round(point->x);
	end.y = point->y + data->gradient * (end.x - point->x);
	gap = gui_rfpart(point->x + 0.5f);
	l->x = end.x;
	l->y = gui_ipart(end.y);
	helper_set_l(data, l, &l1, &l2);
	gui_object_point_f_bundle_build(&bundle, data->buffer, l1,
		data->color, gui_rfpart(end.y) * gap, data->blend);
	gui_object_point_f_plot(&bundle);
	gui_object_point_f_bundle_build(&bundle, data->buffer, l2,
		data->color, gui_fpart(end.y) * gap, data->blend);
	gui_object_point_f_plot(&bundle);
	return (end.y + data->gradient);
}

static void						helper_main(t_gui_object_line_aa_data *data)
{
	float						iter;
	t_gui_object_point_f		temp[2];
	t_gui_object_point_f_bundle	bundle;

	iter = data->l1.x + 1;
	while (iter <= data->l2.x - 1)
	{
		temp[0].x = data->is_steep ? gui_ipart(data->inter) : iter;
		temp[0].y = data->is_steep ? iter : gui_ipart(data->inter);
		temp[1].x = data->is_steep ? gui_ipart(data->inter) + 1 : iter;
		temp[1].y = data->is_steep ? iter : gui_ipart(data->inter) + 1;
		gui_object_point_f_bundle_build(&bundle, data->buffer, temp[0],
			data->color, gui_rfpart(data->inter), data->blend);
		gui_object_point_f_plot(&bundle);
		gui_object_point_f_bundle_build(&bundle, data->buffer, temp[1],
			data->color, gui_fpart(data->inter), data->blend);
		gui_object_point_f_plot(&bundle);
		data->inter = data->inter + data->gradient;
		iter++;
	}
}

void							gui_object_line_plot_aa(
	const t_gui_object_line_bundle *bundle)
{
	t_gui_object_line_aa_data	data;

	data.buffer = bundle->buffer;
	data.from = gui_object_point_i_to_f(bundle->from);
	data.to = gui_object_point_i_to_f(bundle->to);
	data.color = bundle->color;
	data.blend = bundle->blend;
	data.is_steep = abs(bundle->to.y - bundle->from.y)
		> abs(bundle->to.x - bundle->from.x);
	if (data.is_steep)
	{
		swap_memory(&data.from.x, &data.from.y, sizeof(float));
		swap_memory(&data.to.x, &data.to.y, sizeof(float));
	}
	if (data.from.x > data.to.x)
	{
		swap_memory(&data.from.x, &data.to.x, sizeof(float));
		swap_memory(&data.from.y, &data.to.y, sizeof(float));
	}
	data.delta.x = data.to.x - data.from.x;
	data.delta.y = data.to.y - data.from.y;
	data.gradient = data.delta.x ? data.delta.y / data.delta.x : 1.0f;
	data.inter = helper_endpoint(&data, &data.from, &data.l1);
	helper_endpoint(&data, &data.to, &data.l2);
	helper_main(&data);
}
