/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_with_trace_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:09:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:09:19 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_map_with_trace_x.h"

t_gui_map_with_trace		*gui_map_with_trace_new(int fd, void *list)
{
	t_gui_map_with_trace	*map;
	t_gui_callback			callback;

	map = global_malloc(sizeof(t_gui_map_with_trace));
	map->map = gui_map_new(fd);
	callback = gui_callback_set(
		(t_gui_callback_functor)gui_map_with_trace_callback_drag, map, NULL);
	gui_widget_callback_push(map->map->surface_widget,
		gui_surface_signal_drag, callback);
	gui_map_render_back(map->map);
	map->trace = gui_trace_new(fd, map->map, list);
	map->shift_summed = (t_gui_object_point_i){0, 0};
	return (map);
}

void						gui_map_with_trace_delete(
	t_gui_map_with_trace **map)
{
	gui_map_delete(&(*map)->map);
	gui_trace_delete(&(*map)->trace);
	free(*map);
	*map = NULL;
}

void						gui_map_with_trace_render(t_gui_map_with_trace *map)
{
	gui_widget_callback_run(map->map->surface_widget,
		gui_widget_signal_render, NULL, gui_widget_callback_flag_no_test);
	gui_map_render_front(map->map);
	gui_trace_render_ants(map->trace);
}
