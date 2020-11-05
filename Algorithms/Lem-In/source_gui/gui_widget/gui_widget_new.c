/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_widget_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:39:44 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:39:44 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_widget_x.h"
#include "g_system.h"

t_gui_widget		*gui_widget_new(void)
{
	t_gui_widget	*widget;

	widget = global_malloc(sizeof(t_gui_widget));
	widget->info = gui_class_info_set(gui_class_type_widget);
	widget->child = gui_ptr_empty();
	widget->render_buffer = g_settings.buffer_first;
	widget->render_background = GUI_COLOR_BLACK;
	widget->callback_store = vector_create(sizeof(t_gui_callback_list *));
	gui_widget_callback_init_safe(widget, NULL, gui_widget_signal_render);
	widget->state_blocked = global_false;
	widget->state_sensitive = global_true;
	gui_system_add(&g_system, widget);
	return (widget);
}
