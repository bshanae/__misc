/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map_examine_widget.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:06:03 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:06:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_map_x.h"

t_global_bool				gui_map_examine_widget(
	t_gui_map *map, t_gui_widget *widget)
{
	t_gui_button_circle		*circle;

	circle = gui_class_cast(widget, gui_class_type_button_circle);
	if (circle->position.x + circle->radius >= map->surface->max.x)
		return (global_false);
	if (circle->position.y + circle->radius >= map->surface->max.y)
		return (global_false);
	if (circle->position.x - circle->radius <= map->surface->min.x)
		return (global_false);
	if (circle->position.y - circle->radius <= map->surface->min.y)
		return (global_false);
	return (global_true);
}
