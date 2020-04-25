/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_rectangle_bundle.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:14:22 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:14:24 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_bundle.h"

static void						helper_min_max(
	t_gui_object_rectangle_bundle *target, va_list args)
{
	target->min = va_arg(args, t_gui_object_point_i);
	target->max = va_arg(args, t_gui_object_point_i);
}

static void						helper_size(
	t_gui_object_rectangle_bundle *target, va_list args)
{
	t_gui_object_point_i		position;
	t_gui_object_point_i		size;

	position = va_arg(args, t_gui_object_point_i);
	size = va_arg(args, t_gui_object_point_i);
	target->min = (t_gui_object_point_i){position.x - size.x / 2,
		position.y - size.y / 2};
	target->max = (t_gui_object_point_i){position.x + size.x / 2,
		position.y + size.y / 2};
}

t_gui_object_rectangle_bundle	*gui_object_rectangle_bundle_build(
	t_gui_object_rectangle_bundle *target, ...)
{
	va_list						args;

	va_start(args, target);
	target->buffer = va_arg(args, t_gui_buffer *);
	if (va_arg(args, t_global_bool))
		helper_size(target, args);
	else
		helper_min_max(target, args);
	target->color = va_arg(args, t_gui_color);
	target->is_filled = va_arg(args, t_global_bool);
	va_end(args);
	return (target);
}

t_gui_object_rectangle_bundle	*gui_object_rectangle_bundle_build_v(
	t_gui_object_rectangle_bundle *target, va_list args)
{
	target->buffer = va_arg(args, t_gui_buffer *);
	if (va_arg(args, t_global_bool))
		helper_size(target, args);
	else
		helper_min_max(target, args);
	target->color = va_arg(args, t_gui_color);
	target->is_filled = va_arg(args, t_global_bool);
	return (target);
}
