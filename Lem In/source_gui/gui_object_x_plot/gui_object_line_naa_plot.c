/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_line_naa_plot.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:21:10 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:22:37 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_plot.h"

static void						helper_low_init(
	t_gui_object_line_naa_data *data,
	t_gui_object_point_f *d,
	float *df,
	int *incr)
{
	d->x = (float)(data->to.x - data->from.x);
	d->y = (float)(data->to.y - data->from.y);
	*incr = 1;
	if (d->y < 0)
	{
		*incr = -1;
		d->y = -d->y;
	}
	*df = 2 * d->y - d->x;
}

static void						helper_low(t_gui_object_line_naa_data *data)
{
	t_gui_object_point_f		d;
	float						df;
	t_gui_object_point_i		iter;
	int							incr;
	t_gui_object_point_i_bundle	bundle;

	helper_low_init(data, &d, &df, &incr);
	iter.x = data->from.x;
	iter.y = data->from.y;
	while (iter.x <= data->to.x)
	{
		gui_object_point_i_bundle_build(&bundle, data->buffer,
			iter, data->color, 1., data->blend);
		gui_object_point_i_plot(&bundle);
		if (df > 0)
		{
			iter.y += incr;
			df -= 2 * d.x;
		}
		df = df + 2 * d.y;
		iter.x++;
	}
}

static void						helper_high_init(
	t_gui_object_line_naa_data *data,
	t_gui_object_point_f *d,
	float *df,
	int *incr)
{
	d->x = (float)(data->to.x - data->from.x);
	d->y = (float)(data->to.y - data->from.y);
	*incr = 1;
	if (d->x < 0)
	{
		*incr = -1;
		d->x = -d->x;
	}
	*df = 2 * d->x - d->y;
}

static void						helper_high(t_gui_object_line_naa_data *data)
{
	t_gui_object_point_f		d;
	float						df;
	t_gui_object_point_i		iter;
	int							incr;
	t_gui_object_point_i_bundle	bundle;

	helper_high_init(data, &d, &df, &incr);
	iter.x = data->from.x;
	iter.y = data->from.y;
	while (iter.y <= data->to.y)
	{
		gui_object_point_i_bundle_build(&bundle,
			data->buffer, iter, data->color, 1., data->blend);
		gui_object_point_i_plot(&bundle);
		if (df > 0)
		{
			iter.x += incr;
			df -= 2 * d.y;
		}
		df = df + 2 * d.x;
		iter.y++;
	}
}

void							gui_object_line_plot_naa(
	const t_gui_object_line_bundle *bundle)
{
	t_gui_object_line_naa_data	data;

	data.buffer = bundle->buffer;
	data.from = bundle->from;
	data.to = bundle->to;
	data.color = bundle->color;
	data.blend = bundle->blend;
	if (ft_abs(bundle->to.y - bundle->from.y) <
		ft_abs(bundle->to.x - bundle->from.x))
	{
		if (bundle->from.x > bundle->to.x)
			swap_memory(&data.from, &data.to, sizeof(t_gui_object_point_i));
		helper_low(&data);
	}
	else
	{
		if (bundle->from.y > bundle->to.y)
			swap_memory(&data.from, &data.to, sizeof(t_gui_object_point_i));
		helper_high(&data);
	}
}
