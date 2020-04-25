/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_with_trace_x.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:09:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:09:42 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_MAP_WITH_TRACE_X_H
# define GUI_MAP_WITH_TRACE_X_H

# include "gui_map_x.h"
# include "gui_trace_x.h"
# include "gui_map_with_trace.h"

t_gui_map_with_trace	*gui_map_with_trace_new(int fd, void *list);
void					gui_map_with_trace_delete(t_gui_map_with_trace **map);

void					gui_map_with_trace_render(t_gui_map_with_trace *map);

void					gui_map_with_trace_shift(
	t_gui_map_with_trace *map, t_gui_object_point_i shift);

t_global_bool			gui_map_with_trace_callback_drag(
	t_gui_widget *widget, t_gui_map_with_trace *map);

#endif
