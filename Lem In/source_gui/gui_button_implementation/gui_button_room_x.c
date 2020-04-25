/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_room_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:23:35 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:23:35 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button_implementation.h"
#include "gui_map_x.h"

t_gui_button_room				*gui_button_room_new(
	t_gui_object_point_i position, t_gui_map *map, t_global_room *room_ptr)
{
	t_gui_widget				*widget;
	t_gui_button_circle			*circle;
	t_gui_button_room			*room;
	t_gui_callback				callback;

	circle = gui_button_circle_new(position, GUI_BUTTON_ROOM_RADIUS);
	widget = gui_class_cast(circle, gui_class_type_widget);
	room = global_malloc(sizeof(t_gui_button_room));
	widget->surface_test = gui_button_room_test;
	callback = gui_callback_set(gui_button_room_render, NULL, NULL);
	gui_widget_callback_push(widget, gui_widget_signal_render, callback);
	callback = gui_callback_set(gui_button_room_press, NULL, NULL);
	gui_widget_callback_push(widget, gui_button_signal_press, callback);
	callback = gui_callback_set(gui_button_room_release, NULL, NULL);
	gui_widget_callback_push(widget, gui_button_signal_release, callback);
	circle->child = gui_ptr_set(room, free);
	room->info = gui_class_info_set(gui_class_type_button_room);
	room->parent = circle;
	room->map = map;
	room->room = room_ptr;
	room->color = gui_color_set(GUI_BUTTON_ROOM_COLOR);
	if (room_ptr == map->data.start || room_ptr == map->data.end)
		room->color = gui_color_set(GUI_BUTTON_ROOM_COLOR_SPECIAL);
	return (room);
}

t_global_bool					gui_button_room_test(
	t_gui_widget *widget, t_gui_object_point_i *cursor)
{
	return (global_false);
}

t_global_bool					gui_button_room_render(
	t_gui_widget *widget, void *ptr)
{
	t_gui_button_circle			*button_circle;
	t_gui_button_room			*button_room;
	t_gui_color					color;
	t_gui_plugin				*plugin;

	button_circle = gui_class_cast(widget, gui_class_type_button_circle);
	button_room = gui_class_cast(widget, gui_class_type_button_room);
	plugin = button_room->room->plugin;
	color = plugin->highlight ?
		gui_color_set(GUI_BUTTON_ROOM_COLOR_SELECTED) : button_room->color;
	gui_object_plot(gui_object_circle, widget->render_buffer,
		button_circle->position, button_circle->radius, color, global_false);
	return (global_true);
}

t_global_bool					gui_button_room_press(
	t_gui_widget *widget, void *ptr)
{
	t_gui_button_circle			*button_circle;
	t_gui_button_room			*button_room;
	t_gui_plugin				*plugin;
	t_gui_object_point_i		point;

	button_circle = gui_class_cast(widget, gui_class_type_button_circle);
	button_room = gui_class_cast(widget, gui_class_type_button_room);
	plugin = button_room->room->plugin;
	plugin->highlight = global_true;
	if (!gui_map_examine_widget(button_room->map, widget))
		return (global_true);
	point = (t_gui_object_point_i){
		button_circle->position.x,
		button_circle->position.y - button_circle->radius};
	gui_object_plot(gui_object_hint, g_settings.buffer_second,
		g_settings.font_sans14, point, button_room->room->name);
	return (global_true);
}

t_global_bool					gui_button_room_release(
	t_gui_widget *widget, void *ptr)
{
	t_gui_button_circle			*button_circle;
	t_gui_button_room			*button_room;
	t_gui_plugin				*plugin;

	button_circle = gui_class_cast(widget, gui_class_type_button_circle);
	button_room = gui_class_cast(widget, gui_class_type_button_room);
	plugin = button_room->room->plugin;
	plugin->highlight = global_false;
	gui_object_plot(gui_object_circle, widget->render_buffer,
		button_circle->position, button_circle->radius,
		GUI_COLOR_RED, global_false);
	return (global_true);
}
