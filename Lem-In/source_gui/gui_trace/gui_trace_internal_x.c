/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_trace_internal_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:36:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:36:12 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_trace_internal.h"

void					gui_trace_internal_load(
	t_gui_trace *trace, void *list)
{
	int					ant_index;
	t_gui_button_ant	*button;
	t_gui_widget		*widget;

	ant_index = 0;
	while (ant_index < trace->map->data.number_of_ants)
	{
		button = gui_button_ant_new((t_gui_object_point_i){
			trace->map->data.start->x, trace->map->data.start->y},
				trace, list, ant_index++);
		widget = gui_class_cast(button, gui_class_type_widget);
		vector_push(&trace->widgets, &widget);
	}
}
