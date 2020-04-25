/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:59:17 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 14:59:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button.h"

static void			helper_release(t_gui_button *button)
{
	gui_ptr_release(&button->child);
	free(button);
}

t_gui_button		*gui_button_new(void)
{
	t_gui_widget	*widget;
	t_gui_button	*button;
	t_gui_callback	callback;

	widget = gui_widget_new();
	button = global_malloc(sizeof(t_gui_button));
	gui_widget_callback_init_safe(widget,
		gui_button_test_press, gui_button_signal_press);
	gui_widget_callback_init_safe(widget,
		gui_button_test_release, gui_button_signal_release);
	callback = gui_callback_set((t_gui_callback_functor)
		gui_button_callback_press, NULL, NULL);
	gui_widget_callback_push(widget, gui_button_signal_press, callback);
	callback = gui_callback_set((t_gui_callback_functor)
		gui_button_callback_release, NULL, NULL);
	gui_widget_callback_push(widget, gui_button_signal_release, callback);
	widget->child = gui_ptr_set(button, (t_gui_ptr_release)helper_release);
	button->info = gui_class_info_set(gui_class_type_button);
	button->parent = widget;
	button->child = gui_ptr_empty();
	button->state_pressed = global_false;
	button->count_press = 0;
	return (button);
}
