/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_render_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:06:56 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:07:13 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_map_x.h"

static void					helper_rooms(t_gui_map *map)
{
	int						i;
	t_gui_widget			*widget;

	i = 0;
	while (i < map->widgets.length)
	{
		widget = *(t_gui_widget **)vector_at(&map->widgets, i++);
		gui_widget_callback_run(widget, gui_widget_signal_render,
			NULL, gui_widget_callback_flag_no_test);
	}
}

static void					helper_link(
	t_gui_map *map, t_global_room *from, t_global_room *to)
{
	const t_gui_plugin		*plugin_from = from->plugin;
	const t_gui_plugin		*plugin_to = to->plugin;
	t_gui_button_circle		*button_from;
	t_gui_button_circle		*button_to;
	t_gui_color				color;

	button_from = gui_class_cast(plugin_from->widget,
		gui_class_type_button_circle);
	button_to = gui_class_cast(plugin_to->widget, gui_class_type_button_circle);
	color = plugin_from->highlight && plugin_to->highlight ?
		gui_color_set(GUI_MAP_LINK_COLOR_SELECTED) :
		gui_color_set(GUI_MAP_LINK_COLOR);
	gui_object_plot(gui_object_line, map->back_buffer,
		button_from->position, button_to->position,
		global_true, color, global_true);
}

void						helper_links_helper(
	t_gui_map *map, t_queue *queue)
{
	t_gui_state				*state;
	t_global_room			**room_ptr;
	t_global_room			*room;
	int						room_i;
	t_global_room			*room_link;

	while ((room_ptr = queue_front(queue)))
	{
		room = *room_ptr;
		room_i = 0;
		while (room_i < room->links.length)
		{
			room_link = *(t_global_room **)vector_at(&room->links, room_i++);
			state = vector_at(&map->widgets_rendered,
				vector_index(&map->data.data, room_link));
			helper_link(map, room, room_link);
			if (*state == gui_state_not_visited)
			{
				*state = gui_state_visited;
				queue_push(queue, &room_link);
			}
		}
		queue_pop(queue);
	}
}

void						helper_links(t_gui_map *map)
{
	t_gui_state				state_default;
	t_gui_state				*state;
	t_queue					queue;

	state_default = gui_state_not_visited;
	vector_set(&map->widgets_rendered, 0, -1, &state_default);
	queue = queue_create(sizeof(t_global_room *));
	queue_push(&queue, &map->data.start);
	state = vector_at(&map->widgets_rendered,
		vector_index(&map->data.data, map->data.start));
	*state = gui_state_visited;
	helper_links_helper(map, &queue);
	queue_destroy(&queue);
}

void						gui_map_render_back(t_gui_map *map)
{
	gui_buffer_set(map->back_buffer, map->surface_widget->render_background);
	helper_links(map);
	helper_rooms(map);
}
