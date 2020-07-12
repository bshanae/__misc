/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:11:14 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:11:50 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object.h"

void				gui_object_plot(t_gui_object_type type, ...)
{
	va_list			args;
	void			*bundle;

	va_start(args, type);
	bundle = global_malloc(GUI_OBJECT_BUNDLE_MAX);
	gui_object_bundle_build_v(bundle, type, args);
	gui_object_plot_bundle(type, bundle);
	free(bundle);
	va_end(args);
}

void				gui_object_plot_bundle(t_gui_object_type type, void *bundle)
{
	if (type == gui_object_point_i)
		return (gui_object_point_i_plot(bundle));
	else if (type == gui_object_point_f)
		return (gui_object_point_f_plot(bundle));
	else if (type == gui_object_line)
		return (gui_object_line_plot(bundle));
	else if (type == gui_object_circle)
		return (gui_object_circle_plot(bundle));
	else if (type == gui_object_rectangle)
		return (gui_object_rectangle_plot(bundle));
	else if (type == gui_object_hint)
		return (gui_object_hint_plot(bundle));
	else
		global_raise_warning("GUI, Unknown object type");
}

void				*gui_object_bundle_build(
	void *target, t_gui_object_type type, ...)
{
	va_list			args;

	va_start(args, type);
	if (type == gui_object_point_i)
		return (gui_object_point_i_bundle_build(target, args));
	else if (type == gui_object_point_f)
		return (gui_object_point_f_bundle_build(target, args));
	else if (type == gui_object_line)
		return (gui_object_line_bundle_build(target, args));
	else if (type == gui_object_circle)
		return (gui_object_circle_bundle_build(target, args));
	else if (type == gui_object_rectangle)
		return (gui_object_rectangle_bundle_build(target, args));
	else if (type == gui_object_hint)
		return (gui_object_hint_bundle_build(target, args));
	else
		global_raise_warning("GUI, Unknown object type");
	va_end(args);
	return (target);
}

void				*gui_object_bundle_build_v(
	void *target, t_gui_object_type type, va_list args)
{
	if (type == gui_object_point_i)
		return (gui_object_point_i_bundle_build_v(target, args));
	else if (type == gui_object_point_f)
		return (gui_object_point_f_bundle_build_v(target, args));
	else if (type == gui_object_line)
		return (gui_object_line_bundle_build_v(target, args));
	else if (type == gui_object_circle)
		return (gui_object_circle_bundle_build_v(target, args));
	else if (type == gui_object_rectangle)
		return (gui_object_rectangle_bundle_build_v(target, args));
	else if (type == gui_object_hint)
		return (gui_object_hint_bundle_build_v(target, args));
	else
		global_raise_warning("GUI, Unknown object type");
	return (target);
}
