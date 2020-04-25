/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_internal_callback_x.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:47:43 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:47:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_list_internal_x.h"

static t_global_bool		helper_verify_scroll(t_gui_list *list, int diff)
{
	t_gui_widget			**button_widget;
	t_gui_button_rectangle	*button_rectangle;
	int						min;
	int						max;

	if (!(button_widget = vector_at(&list->data.buttons, 0)))
		return (global_false);
	button_rectangle = gui_class_cast(*button_widget,
		gui_class_type_button_rectangle);
	min = button_rectangle->position.y - button_rectangle->size.y / 2;
	if (list->data.buttons.length <= 1)
		return (global_false);
	button_widget = vector_at(&list->data.buttons,
		(int)list->data.buttons.length - 1);
	button_rectangle = gui_class_cast(*button_widget,
		gui_class_type_button_rectangle);
	max = button_rectangle->position.y + button_rectangle->size.y / 2;
	if (min + diff - GUI_LIST_SCROLL_ADD_SPACE > list->settings.window_min.y)
		return (global_false);
	if (max + diff + GUI_LIST_SCROLL_ADD_SPACE < list->settings.window_max.y)
		return (global_false);
	return (global_true);
}

t_global_bool				gui_list_internal_callback_scroll(
	t_gui_widget *widget, void *ptr)
{
	t_gui_list				*list;
	int						shift;
	int						i;
	t_gui_widget			**button_widget;
	t_gui_button_rectangle	*button_button;

	list = gui_class_cast(widget, gui_class_type_list);
	shift = (int)(g_settings.event.shift.y * GUI_LIST_SCROLL_MULT);
	if (!helper_verify_scroll(list, shift))
		return (global_true);
	i = 0;
	while ((button_widget = vector_at(&list->data.buttons, i++)))
	{
		button_button = gui_class_cast(*button_widget,
			gui_class_type_button_rectangle);
		button_button->position.y += shift;
		gui_list_internal_update_block(list, *button_widget);
	}
	gui_widget_callback_run(widget, gui_widget_signal_render,
		NULL, gui_widget_callback_flag_no_test);
	return (global_false);
}
