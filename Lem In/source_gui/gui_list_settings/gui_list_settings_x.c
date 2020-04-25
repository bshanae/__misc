/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_list_settings_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:51:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 15:51:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_list_settings.h"

t_gui_list_settings					gui_list_settings_build(
	t_gui_object_point_i min, t_gui_object_point_i max)
{
	t_gui_list_settings				settings;

	if (max.x < min.x || max.y < min.y)
		global_raise_error("GUI, List : Incorrect list definition");
	settings.window_min = min;
	settings.window_max = max;
	settings.window_color = GUI_COLOR_BLACK;
	settings.window_border = (t_gui_object_point_i){4, 4};
	settings.button_height = GUI_LIST_BUTTON_HEIGHT;
	settings.button_spacing = GUI_LIST_BUTTON_SPACING;
	return (settings);
}

t_gui_list_settings_static			gui_list_settings_parse(
	t_gui_list_settings settings)
{
	t_gui_list_settings_static		result;

	result.window_min = settings.window_min;
	result.window_max = settings.window_max;
	result.window_border = settings.window_border;
	result.window_color = settings.window_color;
	result.button_spacing = settings.button_spacing;
	result.button_size.x = result.window_max.x - result.window_min.x
		- 2 * result.window_border.x - 2;
	result.button_size.y = settings.button_height;
	result.button_first.x = (result.window_max.x + result.window_min.x) / 2 + 1;
	result.button_first.y = result.window_min.y + result.button_size.y / 2
		+ result.window_border.y + 1;
	result.button_next = result.button_first;
	return (result);
}
