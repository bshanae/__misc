/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_system_signal_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:34:27 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:34:28 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_system.h"

t_global_bool				gui_system_signal_test(
	t_gui_system *system, t_gui_widget *widget)
{
	global_assert_critical(widget->surface_test != NULL,
		"GUI, System : Test is NULL");
	return (widget->surface_test(widget, &g_settings.event.position));
}

t_global_bool				gui_system_signal_send(
	t_gui_system *system, t_gui_widget *widget)
{
	int						i;

	i = 0;
	while (i < widget->callback_store.length)
		if (!gui_widget_callback_run(widget, i++, &g_settings.event, 0))
			return (global_false);
	return (global_true);
}

t_global_bool				gui_system_run_event(t_gui_system *system)
{
	t_global_bool			result;
	int						i;
	t_gui_widget			**widget;

	result = global_false;
	i = 0;
	while ((widget = vector_at(&system->data, i++)))
		if (gui_system_signal_test(system, *widget))
		{
			if (!gui_system_signal_send(system, *widget))
			{
				return (global_true);
			}
			result = global_true;
		}
	return (result);
}
