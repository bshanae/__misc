/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_surface_test_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:32:12 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:32:42 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_surface.h"

t_global_bool				gui_surface_test(
	t_gui_widget *widget, t_gui_object_point_i *cursor)
{
	t_gui_surface			*surface;

	surface = gui_class_cast(widget, gui_class_type_surface);
	if (cursor->x < surface->min.x)
		return (global_false);
	if (cursor->y < surface->min.y)
		return (global_false);
	if (cursor->x > surface->max.x)
		return (global_false);
	if (cursor->y > surface->max.y)
		return (global_false);
	return (global_true);
}

t_global_bool				gui_surface_test_move(
	t_gui_widget *widget, t_gui_event *event)
{
	return (event->type == gui_event_type_move);
}

t_global_bool				gui_surface_test_drag(
	t_gui_widget *widget, t_gui_event *event)
{
	return (event->type == gui_event_type_drag);
}

t_global_bool				gui_surface_test_scroll(
	t_gui_widget *widget, t_gui_event *event)
{
	return (event->type == gui_event_type_scroll);
}
