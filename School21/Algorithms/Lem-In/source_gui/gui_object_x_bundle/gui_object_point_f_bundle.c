/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_point_f_bundle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:13:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:13:55 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_bundle.h"

t_gui_object_point_f_bundle		*gui_object_point_f_bundle_build(
	t_gui_object_point_f_bundle *target, ...)
{
	va_list						args;

	va_start(args, target);
	target->buffer = va_arg(args, t_gui_buffer *);
	target->point = va_arg(args, t_gui_object_point_f);
	target->color = va_arg(args, t_gui_color);
	target->alpha = va_arg(args, double);
	target->blend = va_arg(args, t_global_bool);
	va_end(args);
	return (target);
}

t_gui_object_point_f_bundle		*gui_object_point_f_bundle_build_v(
	t_gui_object_point_f_bundle *target, va_list args)
{
	target->buffer = va_arg(args, t_gui_buffer *);
	target->point = va_arg(args, t_gui_object_point_f);
	target->color = va_arg(args, t_gui_color);
	target->alpha = va_arg(args, double);
	target->blend = va_arg(args, t_global_bool);
	return (target);
}
