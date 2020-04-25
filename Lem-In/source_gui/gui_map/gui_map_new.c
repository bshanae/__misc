/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:06:22 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:06:23 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_map_x.h"

static void				helper_min(int *min, const int value)
{
	if (value < *min)
		*min = value;
}

static void				helper_max(int *max, const int value)
{
	if (value > *max)
		*max = value;
}

static void				helper_buttons(t_gui_map *map)
{
	int					i;
	t_global_room		*room;
	t_gui_button_room	*button;
	t_gui_widget		*widget;

	map->min = (t_gui_object_point_i){INT_MAX, INT_MAX};
	map->max = (t_gui_object_point_i){INT_MIN, INT_MIN};
	i = 0;
	while (i < map->data.data.length)
	{
		room = vector_at(&map->data.data, i++);
		helper_min(&map->min.x, room->x - GUI_BUTTON_ROOM_RADIUS);
		helper_min(&map->min.y, room->y - GUI_BUTTON_ROOM_RADIUS);
		helper_max(&map->max.x, room->x + GUI_BUTTON_ROOM_RADIUS);
		helper_max(&map->max.y, room->y + GUI_BUTTON_ROOM_RADIUS);
		button = gui_button_room_new((t_gui_object_point_i){room->x, room->y},
			map, room);
		widget = gui_class_cast(button, gui_class_type_widget);
		widget->render_buffer = map->back_buffer;
		widget->render_background = map->surface_widget->render_background;
		room->plugin = global_room_plugin_new(widget);
		vector_push(&map->widgets, &widget);
	}
}

t_gui_map				*gui_map_new(int fd)
{
	t_gui_map			*map;

	map = global_malloc(sizeof(t_gui_map));
	map->surface = gui_surface_new(GUI_MAP_MIN, GUI_MAP_MAX);
	map->surface_widget = gui_class_cast(map->surface, gui_class_type_widget);
	map->surface_widget->render_background = gui_color_set(GUI_MAP_BACKGROUND);
	map->back_buffer = gui_buffer_new(GUI_WIDTH, GUI_HEIGHT);
	map->data = global_map_create();
	global_map_parse(&map->data, fd);
	map->widgets = vector_create(sizeof(t_gui_widget *));
	map->widgets_rendered = vector_create(sizeof(t_gui_state));
	vector_resize(&map->widgets_rendered, map->data.data.length, NULL);
	helper_buttons(map);
	return (map);
}
