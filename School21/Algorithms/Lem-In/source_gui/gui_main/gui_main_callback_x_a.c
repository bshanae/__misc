/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_main_callback_x_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:53:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:53:45 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_main.h"

Uint32					gui_main_callback_render(
	Uint32 interval, t_gui_main *main)
{
	if (main->map->trace->work_block)
		return (interval);
	if (main->map->trace->render_state == gui_trace_paused)
		return (interval);
	if (main->map->trace->render_progress > 1.f)
		if (!gui_trace_step_forward(main->map->trace))
		{
			gui_widget_callback_run(main->menu.menu_middle,
				gui_button_signal_press, NULL,
				gui_widget_callback_flag_no_test);
			gui_widget_callback_run(main->menu.menu_middle,
				gui_button_signal_release, NULL,
				gui_widget_callback_flag_no_test);
			return (interval);
		}
	main->map->trace->render_progress += 0.05f;
	main->menu.timer_render_request = global_true;
	return (interval);
}

t_global_bool			gui_main_callback_list_select(
	t_gui_widget *widget, void *ptr)
{
	t_gui_list			*list;
	t_gui_button_list	*button;

	list = gui_class_cast(widget, gui_class_type_list);
	button = gui_class_cast(list->selected, gui_class_type_button_list);
	list->selected->state_blocked = global_true;
	gui_widget_callback_run(button->ptr.ptr, gui_button_signal_press,
		NULL, gui_widget_callback_flag_no_test);
	gui_widget_callback_run(button->ptr.ptr, gui_button_signal_release,
		NULL, gui_widget_callback_flag_no_test);
	list->selected->state_blocked = global_false;
	return (global_true);
}

t_global_bool			gui_main_callback_list_unselect(
	t_gui_widget *widget, void *ptr)
{
	t_gui_list			*list;
	t_gui_button_list	*button;

	list = gui_class_cast(widget, gui_class_type_list);
	button = gui_class_cast(list->unselected, gui_class_type_button_list);
	list->unselected->state_blocked = global_true;
	gui_widget_callback_run(button->ptr.ptr, gui_button_signal_press,
		NULL, gui_widget_callback_flag_no_test);
	gui_widget_callback_run(button->ptr.ptr, gui_button_signal_release,
		NULL, gui_widget_callback_flag_no_test);
	list->unselected->state_blocked = global_false;
	return (global_true);
}
