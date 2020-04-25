/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_widget_callback_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:39:00 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:39:05 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_widget_x.h"

int						gui_widget_callback_init(
	t_gui_widget *widget, t_gui_callback_list_test test)
{
	t_gui_callback_list	*list;

	list = gui_callback_list_new(test);
	return (vector_push(&widget->callback_store, &list).index);
}

int						gui_widget_callback_init_safe(
	t_gui_widget *widget, t_gui_callback_list_test test, int index)
{
	if (widget->callback_store.length != index)
		global_raise_error("GUI, Widget : Can't init signal with given index");
	return (gui_widget_callback_init(widget, test));
}

void					gui_widget_callback_push(
	t_gui_widget *widget, int index, t_gui_callback callback)
{
	t_gui_callback_list	*list;

	if (index < 0 || index >= widget->callback_store.length)
		return ((global_raise_warning("GUI, Widget : Unknown signal")));
	list = *(t_gui_callback_list **)vector_at(&widget->callback_store, index);
	gui_callback_list_push(list, callback);
}

t_global_bool			gui_widget_callback_pop(t_gui_widget *widget, int index)
{
	t_gui_callback_list	*list;

	if (index < 0 || index >= widget->callback_store.length)
	{
		global_raise_warning("GUI, Widget : Unknown signal");
		return (global_false);
	}
	list = *(t_gui_callback_list **)vector_at(&widget->callback_store, index);
	return (gui_callback_list_pop(list));
}

t_global_bool			gui_widget_callback_run(
	t_gui_widget *widget, int index, t_gui_event *event, UINT flags)
{
	t_gui_callback_list	*list;

	if (index < 0 || index >= widget->callback_store.length)
	{
		global_raise_warning("GUI, Widget : Unknown signal");
		return (global_true);
	}
	if (widget->state_blocked &&
		!(flags & gui_widget_callback_flag_ignore_block))
		return (global_true);
	if (!widget->state_sensitive && index != gui_widget_signal_render &&
		!(flags & gui_widget_callback_flag_ignore_sensitive))
		return (global_true);
	list = *(t_gui_callback_list **)vector_at(&widget->callback_store, index);
	if (!(flags & gui_widget_callback_flag_no_test))
		if (!gui_callback_list_test(list, widget, event))
			return (global_true);
	return (gui_callback_list_run(list, widget));
}
