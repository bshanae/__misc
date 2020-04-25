/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_surface_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:31:48 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:31:48 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_surface.h"

t_gui_surface			*gui_surface_new(
	t_gui_object_point_i min, t_gui_object_point_i max)
{
	t_gui_widget		*widget;
	t_gui_surface		*surface;
	t_gui_callback		callback;

	widget = gui_widget_new();
	surface = global_malloc(sizeof(t_gui_surface));
	widget->child = gui_ptr_set(surface, free);
	widget->surface_test = gui_surface_test;
	callback = gui_callback_set(gui_surface_render, NULL, NULL);
	gui_widget_callback_push(widget, gui_widget_signal_render, callback);
	gui_widget_callback_init_safe(widget, gui_surface_test_move,
		gui_surface_signal_move);
	gui_widget_callback_init_safe(widget, gui_surface_test_drag,
		gui_surface_signal_drag);
	gui_widget_callback_init_safe(widget, gui_surface_test_scroll,
		gui_surface_signal_scroll);
	surface->info = gui_class_info_set(gui_class_type_surface);
	surface->parent = widget;
	surface->child = gui_ptr_empty();
	surface->min = min;
	surface->max = max;
	return (surface);
}
