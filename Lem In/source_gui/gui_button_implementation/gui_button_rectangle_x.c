/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_rectangle_x.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:22:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:22:09 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button_implementation.h"

static void					helper_release(t_gui_button_rectangle *rectangle)
{
	gui_ptr_release(&rectangle->child);
	free(rectangle);
}

t_gui_button_rectangle		*gui_button_rectangle_new(
	t_gui_object_point_i position, t_gui_object_point_i size)
{
	t_gui_widget			*widget;
	t_gui_button			*button;
	t_gui_button_rectangle	*rectangle;
	t_gui_callback			callback;

	button = gui_button_new();
	widget = gui_class_cast(button, gui_class_type_widget);
	rectangle = global_malloc(sizeof(t_gui_button_rectangle));
	callback = gui_callback_set(gui_button_rectangle_render, NULL, NULL);
	gui_widget_callback_push(widget, gui_widget_signal_render, callback);
	button->child = gui_ptr_set(rectangle, (t_gui_ptr_release)helper_release);
	button->parent->surface_test = gui_button_rectangle_test;
	rectangle->info = gui_class_info_set(gui_class_type_button_rectangle);
	rectangle->parent = button;
	rectangle->position = position;
	rectangle->size = size;
	return (rectangle);
}

t_global_bool				gui_button_rectangle_test(
	t_gui_widget *widget, t_gui_object_point_i *cursor)
{
	t_gui_button			*button;
	t_gui_button_rectangle	*rectangle;

	button = gui_class_cast(widget, gui_class_type_button);
	rectangle = gui_class_cast(button, gui_class_type_button_rectangle);
	if (cursor->x < rectangle->position.x - rectangle->size.x / 2)
		return (global_false);
	if (cursor->x > rectangle->position.x + rectangle->size.x / 2)
		return (global_false);
	if (cursor->y < rectangle->position.y - rectangle->size.y / 2)
		return (global_false);
	if (cursor->y > rectangle->position.y + rectangle->size.y / 2)
		return (global_false);
	return (global_true);
}

t_global_bool				gui_button_rectangle_render(
	t_gui_widget *widget, void *ptr)
{
	t_gui_button_rectangle	*rectangle;

	rectangle = gui_class_cast(widget, gui_class_type_button_rectangle);
	gui_object_plot(gui_object_rectangle, widget->render_buffer,
		global_true, rectangle->position, rectangle->size,
		widget->render_background, global_true);
	return (global_true);
}
