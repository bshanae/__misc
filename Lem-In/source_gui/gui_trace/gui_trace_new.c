/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_trace_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:36:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:36:50 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_trace_x.h"
#include "gui_trace_internal.h"

t_gui_trace					*gui_trace_new(int fd, t_gui_map *map, void *list)
{
	t_gui_trace				*trace;

	trace = global_malloc(sizeof(t_gui_trace));
	trace->data = global_trace_create(&map->data);
	global_trace_parse(&trace->data, fd);
	trace->map = map;
	trace->widgets = vector_create(sizeof(t_gui_widget *));
	trace->render_cycle = 1;
	trace->render_progress = 0.f;
	trace->render_state = gui_trace_rendering;
	trace->work_block = global_false;
	trace->selected_path = NULL;
	gui_trace_internal_load(trace, list);
	return (trace);
}
