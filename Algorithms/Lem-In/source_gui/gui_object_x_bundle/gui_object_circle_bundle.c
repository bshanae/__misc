/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_circle_bundle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:12:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:12:58 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_bundle.h"

t_gui_object_circle_bundle		*gui_object_circle_bundle_build(
	t_gui_object_circle_bundle *target, ...)
{
	va_list						args;

	va_start(args, target);
	target->buffer = va_arg(args, t_gui_buffer *);
	target->position = va_arg(args, t_gui_object_point_i);
	target->radius = va_arg(args, int);
	target->color = va_arg(args, t_gui_color);
	target->is_filled = va_arg(args, t_global_bool);
	va_end(args);
	return (target);
}

t_gui_object_circle_bundle		*gui_object_circle_bundle_build_v(
	t_gui_object_circle_bundle *target, va_list args)
{
	target->buffer = va_arg(args, t_gui_buffer *);
	target->position = va_arg(args, t_gui_object_point_i);
	target->radius = va_arg(args, int);
	target->color = va_arg(args, t_gui_color);
	target->is_filled = va_arg(args, t_global_bool);
	return (target);
}
