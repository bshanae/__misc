/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_with_trace_shift.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:08:52 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:08:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_map_with_trace_x.h"

static t_global_bool		helper_verify(
	t_gui_map_with_trace *map, t_gui_object_point_i shift_total)
{
	if (map->map->max.x + shift_total.x - GUI_MAP_DRAG_LIMIT
		<= map->map->surface->min.x)
		return (global_false);
	if (map->map->max.y + shift_total.y - GUI_MAP_DRAG_LIMIT
		<= map->map->surface->min.y)
		return (global_false);
	if (map->map->min.x + shift_total.x + GUI_MAP_DRAG_LIMIT
		>= map->map->surface->max.x)
		return (global_false);
	if (map->map->min.y + shift_total.y + GUI_MAP_DRAG_LIMIT
		>= map->map->surface->max.y)
		return (global_false);
	return (global_true);
}

static void					helper_shift(
	t_gui_object_point_i *point, const t_gui_object_point_i *shift)
{
	point->x += shift->x;
	point->y += shift->y;
}

static void					helper_widgets(
	t_vector *vector, const t_gui_object_point_i *shift)
{
	int						i;
	t_gui_widget			**widget2;
	t_gui_button_circle		*circle;

	i = 0;
	while ((widget2 = vector_at(vector, i++)))
	{
		circle = gui_class_cast(*widget2, gui_class_type_button_circle);
		helper_shift(&circle->position, shift);
	}
}

void						gui_map_with_trace_shift(
	t_gui_map_with_trace *map, t_gui_object_point_i shift)
{
	t_gui_object_point_i	shift_total;

	shift_total.x = map->shift_summed.x + shift.x;
	shift_total.y = map->shift_summed.y + shift.y;
	if (!helper_verify(map, shift_total))
		return ;
	map->shift_summed = shift_total;
	gui_buffer_clear(map->map->back_buffer);
	helper_widgets(&map->map->widgets, &shift);
	helper_widgets(&map->trace->widgets, &shift);
	gui_map_render_back(map->map);
}
