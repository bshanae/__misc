/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_trace_render_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:37:05 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:37:06 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_trace_x.h"

void				gui_trace_render_ants(t_gui_trace *trace)
{
	int				i;
	t_gui_widget	**widget2;

	i = 0;
	while ((widget2 = vector_at(&trace->widgets, i++)))
		gui_widget_callback_run(*widget2,
			gui_widget_signal_render, NULL, gui_widget_callback_flag_no_test);
}

static void			helper_cycle(t_vector *path, t_global_bool is_selected)
{
	int				i;
	t_global_room	*room_ptr;
	t_gui_plugin	*room_plugin;
	t_gui_widget	*room_widget;

	i = 0;
	while (i < path->length)
	{
		room_ptr = *(t_global_room **)vector_at(path, i++);
		room_plugin = room_ptr->plugin;
		room_widget = room_plugin->widget;
		if (is_selected)
			gui_widget_callback_run(room_widget, gui_button_signal_press,
				NULL, gui_widget_callback_flag_no_test);
		else
			gui_widget_callback_run(room_widget, gui_button_signal_release,
				NULL, gui_widget_callback_flag_no_test);
	}
}

void				gui_trace_render_path(
	t_gui_trace *trace, t_vector *path, t_global_bool is_selected)
{
	if (!path && !trace->selected_path)
		return ;
	gui_buffer_clear(g_settings.buffer_second);
	if (!path)
	{
		path = trace->selected_path;
		is_selected = global_true;
	}
	else
		trace->selected_path = is_selected ? path : NULL;
	helper_cycle(path, is_selected);
}
