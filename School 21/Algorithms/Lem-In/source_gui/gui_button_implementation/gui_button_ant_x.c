/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button_ant_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:03:13 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:03:13 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button_implementation.h"
#include "gui_map_x.h"
#include "gui_trace_x.h"

t_gui_button_ant			*gui_button_ant_new(
	t_gui_object_point_i position,
	t_gui_trace *trace, t_gui_list *list, int index)
{
	t_gui_widget			*widget;
	t_gui_button_circle		*circle;
	t_gui_button_ant		*ant;
	t_gui_callback			callback;

	circle = gui_button_circle_new(position, GUI_BUTTON_ANT_RADIUS);
	widget = gui_class_cast(circle, gui_class_type_widget);
	ant = global_malloc(sizeof(t_gui_button_ant));
	gui_widget_callback_pop(widget, gui_widget_signal_render);
	callback = gui_callback_set(gui_button_ant_render, NULL, NULL);
	gui_widget_callback_push(widget, gui_widget_signal_render, callback);
	callback = gui_callback_set(gui_button_ant_press, NULL, NULL);
	gui_widget_callback_push(widget, gui_button_signal_press, callback);
	callback = gui_callback_set(gui_button_ant_release, NULL, NULL);
	gui_widget_callback_push(widget, gui_button_signal_release, callback);
	circle->child = gui_ptr_set(ant, free);
	ant->info = gui_class_info_set(gui_class_type_button_ant);
	ant->parent = circle;
	ant->trace = trace;
	ant->list = list;
	ant->index = index;
	ant->path = vector_at(&ant->trace->data.data, ant->index);
	ant->last_cycle = 1;
	ant->last_progress = 0.f;
	return (ant);
}

static void					helper_position(
	t_gui_button_circle *me_circle, t_gui_button_ant *me_ant)
{
	t_global_room			*room[2];
	t_gui_widget			*widget[2];
	t_gui_button_circle		*circle[2];
	t_gui_object_point_f	delta;

	room[0] = *(t_global_room **)vector_at(me_ant->path,
		me_ant->trace->render_cycle - 1);
	room[1] = *(t_global_room **)vector_at(me_ant->path,
		me_ant->trace->render_cycle);
	widget[0] = ((t_gui_plugin *)room[0]->plugin)->widget;
	widget[1] = ((t_gui_plugin *)room[1]->plugin)->widget;
	circle[0] = gui_class_cast(widget[0], gui_class_type_button_circle);
	circle[1] = gui_class_cast(widget[1], gui_class_type_button_circle);
	delta.x = (float)(circle[1]->position.x - circle[0]->position.x) *
		me_ant->trace->render_progress;
	delta.y = (float)(circle[1]->position.y - circle[0]->position.y) *
		me_ant->trace->render_progress;
	me_circle->position.x = circle[0]->position.x + (int)delta.x;
	me_circle->position.y = circle[0]->position.y + (int)delta.y;
}

t_global_bool				gui_button_ant_render(
	t_gui_widget *widget, void *ptr)
{
	t_gui_button			*button;
	t_gui_button_circle		*circle;
	t_gui_button_ant		*ant;

	button = gui_class_cast(widget, gui_class_type_button);
	circle = gui_class_cast(widget, gui_class_type_button_circle);
	ant = gui_class_cast(widget, gui_class_type_button_ant);
	if (ant->last_cycle != ant->trace->render_cycle ||
		ant->last_progress != ant->trace->render_progress)
		helper_position(circle, ant);
	ant->last_cycle = ant->trace->render_cycle;
	ant->last_progress = ant->trace->render_progress;
	if (!gui_map_examine_widget(ant->trace->map, widget))
		return (global_true);
	gui_object_plot(gui_object_circle, widget->render_buffer, circle->position,
		GUI_BUTTON_ANT_RADIUS,
		button->count_press % 2 ?
		gui_color_set(GUI_BUTTON_ANT_COLOR_SELECTED) :
		gui_color_set(GUI_BUTTON_ANT_COLOR),
		global_true);
	return (global_true);
}

t_global_bool				gui_button_ant_press(
	t_gui_widget *widget, void *ptr)
{
	t_gui_button_ant		*ant;

	ant = gui_class_cast(widget, gui_class_type_button_ant);
	gui_widget_callback_run(ant->trace->map->surface_widget,
		gui_widget_signal_render, NULL, gui_widget_callback_flag_no_test);
	gui_widget_callback_run(widget,
		gui_widget_signal_render, NULL, gui_widget_callback_flag_no_test);
	gui_map_render_front(ant->trace->map);
	gui_trace_render_ants(ant->trace);
	return (global_true);
}

t_global_bool				gui_button_ant_release(
	t_gui_widget *widget, void *ptr)
{
	t_gui_button			*button;
	t_gui_button_ant		*ant;

	button = gui_class_cast(widget, gui_class_type_button);
	ant = gui_class_cast(widget, gui_class_type_button_ant);
	widget->state_blocked = global_true;
	gui_list_select(ant->list, ant->index);
	widget->state_blocked = global_false;
	gui_trace_render_path(ant->trace, ant->path, button->count_press % 2);
	gui_widget_callback_run(ant->trace->map->surface_widget,
		gui_widget_signal_render, NULL, gui_widget_callback_flag_no_test);
	gui_map_render_back(ant->trace->map);
	gui_map_render_front(ant->trace->map);
	gui_trace_render_ants(ant->trace);
	return (global_false);
}
