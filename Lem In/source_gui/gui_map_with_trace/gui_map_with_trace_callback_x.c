/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_with_trace_callback_x.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:08:40 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:08:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_map_with_trace_x.h"

t_global_bool				gui_map_with_trace_callback_drag(
	t_gui_widget *widget, t_gui_map_with_trace *map)
{
	gui_map_with_trace_shift(map, g_settings.event.shift);
	gui_map_with_trace_render(map);
	gui_trace_render_path(map->trace, NULL, 0);
	return (global_true);
}
