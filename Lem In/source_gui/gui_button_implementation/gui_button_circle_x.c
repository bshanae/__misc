/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_circle_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:00:46 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:00:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button_implementation.h"

static void						helper_release(t_gui_button_circle *circle)
{
	gui_ptr_release(&circle->child);
	free(circle);
}

t_gui_button_circle				*gui_button_circle_new(
	t_gui_object_point_i position, int radius)
{
	t_gui_widget				*widget;
	t_gui_button				*button;
	t_gui_button_circle			*circle;
	t_gui_callback				callback;

	button = gui_button_new();
	widget = gui_class_cast(button, gui_class_type_widget);
	circle = global_malloc(sizeof(t_gui_button_circle));
	button->child = gui_ptr_set(circle, (t_gui_ptr_release)helper_release);
	widget->surface_test = gui_button_circle_test;
	callback = gui_callback_set(gui_button_circle_render, NULL, NULL);
	gui_widget_callback_push(widget, gui_widget_signal_render, callback);
	circle->info = gui_class_info_set(gui_class_type_button_circle);
	circle->parent = button;
	circle->child = gui_ptr_empty();
	circle->position = position;
	circle->radius = radius;
	return (circle);
}

t_global_bool					gui_button_circle_test(
	t_gui_widget *widget, t_gui_object_point_i *cursor)
{
	t_gui_button				*button;
	t_gui_button_circle			*circle;
	float						distance;

	button = gui_class_cast(widget, gui_class_type_button);
	circle = button->child.ptr;
	distance = (float)(
		(circle->position.x - cursor->x) * (circle->position.x - cursor->x) +
		(circle->position.y - cursor->y) * (circle->position.y - cursor->y));
	distance = sqrtf(distance);
	return (distance < (float)circle->radius);
}

t_global_bool					gui_button_circle_render(
	t_gui_widget *widget, void *ptr)
{
	t_gui_button_circle			*button_circle;

	button_circle = gui_class_cast(widget, gui_class_type_button_circle);
	gui_object_plot(gui_object_circle, widget->render_buffer,
		button_circle->position, button_circle->radius,
		widget->render_background, global_true);
	return (global_true);
}
