/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_list_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:03:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:03:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button_implementation.h"

static void					helper_release(t_gui_button_list *list)
{
	gui_ptr_release(&list->ptr);
	free(list);
}

t_gui_button_list			*gui_button_list_new(
	t_gui_object_point_i position,
	t_gui_object_point_i size, CHAR_REF str, t_gui_ptr ptr)
{
	t_gui_widget			*widget;
	t_gui_button_text		*text;
	t_gui_button_list		*list;
	t_gui_callback			callback;

	text = gui_button_text_new(position, size, str);
	widget = gui_class_cast(text, gui_class_type_widget);
	list = global_malloc(sizeof(t_gui_button_list));
	callback = gui_callback_set(gui_button_list_release, NULL, NULL);
	gui_widget_callback_push(widget, gui_button_signal_release, callback);
	text->child = gui_ptr_set(list, (t_gui_ptr_release)helper_release);
	list->info = gui_class_info_set(gui_class_type_button_list);
	list->parent = text;
	list->list = NULL;
	list->ptr = ptr;
	return (list);
}

static t_global_bool		helper_a(
	t_gui_widget *widget, t_gui_widget *list_widget,
	t_gui_button *button, t_gui_button_list *button_list)
{
	if (button->count_press % 2 != 1)
		return (global_true);
	if (button_list->list->selected)
	{
		gui_widget_callback_run(button_list->list->selected,
			gui_button_signal_press, NULL, gui_widget_callback_flag_no_test);
		gui_widget_callback_run(button_list->list->selected,
			gui_button_signal_release, NULL, gui_widget_callback_flag_no_test);
	}
	else
		button_list->list->unselected = NULL;
	button_list->list->selected = widget;
	gui_widget_callback_run(list_widget,
		gui_list_signal_select, NULL, gui_widget_callback_flag_no_test);
	return (global_false);
}

static t_global_bool		helper_b(
	t_gui_widget *widget, t_gui_widget *list_widget,
	t_gui_button *button, t_gui_button_list *button_list)
{
	if (button->count_press % 2 != 0)
		return (global_true);
	button_list->list->unselected = button_list->list->selected;
	button_list->list->selected = NULL;
	gui_widget_callback_run(list_widget,
		gui_list_signal_unselect, NULL, gui_widget_callback_flag_no_test);
	return (global_false);
}

t_global_bool				gui_button_list_release(
	t_gui_widget *widget, void *ptr)
{
	t_gui_button			*button;
	t_gui_button_list		*button_list;
	t_gui_widget			*list_widget;

	button = gui_class_cast(widget, gui_class_type_button);
	button_list = gui_class_cast(button, gui_class_type_button_list);
	list_widget = gui_class_cast(button_list->list, gui_class_type_widget);
	global_assert_critical(button_list->list != NULL,
		"GUI, List : Ptr in button not set");
	if (button_list->list->selected != widget)
	{
		if (helper_a(widget, list_widget, button, button_list))
			return (global_true);
	}
	else
	{
		if (helper_b(widget, list_widget, button, button_list))
			return (global_true);
	}
	return (global_false);
}
