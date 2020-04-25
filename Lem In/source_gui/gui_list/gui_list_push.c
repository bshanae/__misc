/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:50:00 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:50:01 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_list_x.h"
#include "gui_list_internal_x.h"

void						gui_list_push(
	t_gui_list *list, CHAR_REF str, t_gui_ptr ptr)
{
	t_gui_widget			*list_widget;
	t_gui_button_list		*button_button;
	t_gui_widget			*button_widget;

	button_button = gui_button_list_new(list->settings.button_next,
		list->settings.button_size, str, ptr);
	button_button->list = list;
	list_widget = gui_class_cast(list, gui_class_type_widget);
	button_widget = gui_class_cast(button_button, gui_class_type_widget);
	button_widget->render_background = list_widget->render_background;
	vector_push(&list->data.buttons, &button_widget);
	list->settings.button_next.y += list->settings.button_size.y +
		list->settings.button_spacing;
	gui_list_internal_update_block(list, button_widget);
}
