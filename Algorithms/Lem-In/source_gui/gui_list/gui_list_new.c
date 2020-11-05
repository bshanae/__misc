/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:49:47 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:49:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_list_x.h"
#include "gui_list_internal_x.h"

static void						helper_release(t_gui_list *list)
{
	vector_destroy(&list->data.buttons);
	free(list);
}

t_gui_list						*gui_list_new(t_gui_list_settings settings)
{
	t_gui_widget				*widget;
	t_gui_surface				*surface;
	t_gui_list					*list;
	t_gui_callback				callback;

	surface = gui_surface_new(settings.window_min, settings.window_max);
	widget = gui_class_cast(surface, gui_class_type_widget);
	list = global_malloc(sizeof(t_gui_list));
	surface->child = gui_ptr_set(list, (t_gui_ptr_release)helper_release);
	widget->render_background = settings.window_color;
	callback = gui_callback_set(gui_list_internal_callback_render, NULL, NULL);
	gui_widget_callback_push(widget, gui_widget_signal_render, callback);
	callback = gui_callback_set(gui_list_internal_callback_scroll, NULL, NULL);
	gui_widget_callback_push(widget, gui_surface_signal_scroll, callback);
	gui_widget_callback_init_safe(widget, NULL, gui_list_signal_select);
	gui_widget_callback_init_safe(widget, NULL, gui_list_signal_unselect);
	list->info = gui_class_info_set(gui_class_type_list);
	list->parent = surface;
	list->data.buttons = vector_create(sizeof(t_gui_widget *));
	gui_list_internal_load_settings(list, settings);
	list->unselected = NULL;
	list->selected = NULL;
	return (list);
}

t_gui_list						*gui_list_new_default(
	t_gui_object_point_i min, t_gui_object_point_i max)
{
	t_gui_list_settings			settings;

	settings = gui_list_settings_build(min, max);
	return (gui_list_new(settings));
}
