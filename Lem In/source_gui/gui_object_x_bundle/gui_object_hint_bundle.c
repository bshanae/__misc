/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_hint_bundle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:13:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:13:19 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x_bundle.h"

t_gui_object_hint_bundle	*gui_object_hint_bundle_build(
	t_gui_object_hint_bundle *target, ...)
{
	va_list					args;

	va_start(args, target);
	target->buffer = va_arg(args, t_gui_buffer *);
	target->font = va_arg(args, t_gui_font *);
	target->lower_point = va_arg(args, t_gui_object_point_i);
	target->name = va_arg(args, CHAR_REF);
	va_end(args);
	return (target);
}

t_gui_object_hint_bundle	*gui_object_hint_bundle_build_v(
	t_gui_object_hint_bundle *target, va_list args)
{
	target->buffer = va_arg(args, t_gui_buffer *);
	target->font = va_arg(args, t_gui_font *);
	target->lower_point = va_arg(args, t_gui_object_point_i);
	target->name = va_arg(args, CHAR_REF);
	return (target);
}
